<?php

    require(__DIR__ . "/../includes/config.php");

    // ensure proper usage
    if (!isset($_GET["sw"], $_GET["ne"]))
    {
        http_response_code(400);
        exit;
    }

    // ensure each parameter is in lat,lng format
    if (!preg_match("/^-?\d+(?:\.\d+)?,-?\d+(?:\.\d+)?$/", $_GET["sw"]) ||
        !preg_match("/^-?\d+(?:\.\d+)?,-?\d+(?:\.\d+)?$/", $_GET["ne"]))
    {
        http_response_code(400);
        exit;
    }

    // explode southwest corner into two variables
    list($sw_lat, $sw_lng) = explode(",", $_GET["sw"]);

    // explode northeast corner into two variables
    list($ne_lat, $ne_lng) = explode(",", $_GET["ne"]);

    // find 10 cities within view, pseudorandomly chosen if more within view
    if ($sw_lng <= $ne_lng)
    {
        // doesn't cross the antimeridian FROM builds was FROM places, NgTW
        $rows = CS50::query("SELECT * FROM places WHERE ? <= latitude AND latitude <= ? AND (? <= longitude AND longitude <= ?) 
        GROUP BY country_code, place_name, admin_code1 ORDER BY RAND() LIMIT 10", $sw_lat, $ne_lat, $sw_lng, $ne_lng);
    }
    else
    {
        // crosses the antimeridian FROM builds was FROM places, NgTW
        $rows = CS50::query("SELECT * FROM places WHERE ? <= latitude AND latitude <= ? AND (? <= longitude OR longitude <= ?) 
        GROUP BY country_code, place_name, admin_code1 ORDER BY RAND() LIMIT 10", $sw_lat, $ne_lat, $sw_lng, $ne_lng);
    }
    //dump($rows);//debug

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($rows, JSON_PRETTY_PRINT));



/*** I think data got problem
removed the contents of sql/description - it work!

replaced * by country_code, place_name, admin_name1 - can output json, but still no Marker. Not working
was $rows = CS50::query("SELECT * FROM builds ....

replaced * by place_name - 
was $rows = CS50::query("SELECT * FROM builds ....

//GROUP_BY country_code, place_name, admin_code1 ORDER BY RAND() LIMIT 10", $sw_lat, $ne_lat, $sw_lng, $ne_lng);

Object {ne: "1.435805318216114,103.95359619140618", q: undefined, sw: "1.264191653388732,103.70640380859368"}
check output:
old /update.php?ne=37.45%2C-122.03&q=&sw=37.39%2C-122.28

https://ide50-twng.cs50.io/update.php?ne=1.4358%2C-103.9535&q=&sw=1.2642%2C-103.7064


was:
    {
        // doesn't cross the antimeridian FROM builds was FROM places, NgTW
        $rows = CS50::query("SELECT * FROM builds WHERE ? <= latitude AND latitude <= ? AND (? <= longitude AND longitude <= ?) 
        GROUP BY country_code, place_name, admin_code1 ORDER BY RAND() LIMIT 10", $sw_lat, $ne_lat, $sw_lng, $ne_lng);
    }
    else
    {
        // crosses the antimeridian FROM builds was FROM places, NgTW
        $rows = CS50::query("SELECT * FROM builds WHERE ? <= latitude AND latitude <= ? AND (? <= longitude OR longitude <= ?) 
        GROUP BY country_code, place_name, admin_code1 ORDER BY RAND() LIMIT 10", $sw_lat, $ne_lat, $sw_lng, $ne_lng);
    }

now: was: SELECT * FROM builds WHERE country_code = 'SG'"); 
SELECT * FROM builds JOIN places ON builds.place_name = places.place_name  WHERE places.country_code = 'SG'
*/

?>