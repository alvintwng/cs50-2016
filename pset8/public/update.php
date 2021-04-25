<?php
/** update.php
 * data download from http://download.geonames.org/export/zip/
 * check details on http://www.geonames.org/countries/
 */

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
        // doesn't cross the antimeridian
        $rows = CS50::query("SELECT * FROM places WHERE ? <= latitude AND latitude <= ? AND (? <= longitude AND longitude <= ?) GROUP BY country_code, place_name, admin_code1 ORDER BY RAND() LIMIT 10", $sw_lat, $ne_lat, $sw_lng, $ne_lng);
    }
    else
    {
        // crosses the antimeridian
        $rows = CS50::query("SELECT * FROM places WHERE ? <= latitude AND latitude <= ? AND (? <= longitude OR longitude <= ?) GROUP_BY country_code, place_name, admin_code1 ORDER BY RAND() LIMIT 10", $sw_lat, $ne_lat, $sw_lng, $ne_lng);
    }

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($rows, JSON_PRETTY_PRINT));



/* check output:
https://ide50-twng.cs50.io/update.php?ne=37.4%2C-122.0&q=&sw=37.3%2C-122.2

screen output example as follow:
[
    {
        "id": "4453",
        "country_code": "US",
        "postal_code": "94022",
        "place_name": "Los Altos",
        "admin_name1": "California",
        "admin_code1": "CA",
        "admin_name2": "Santa Clara",
        "admin_code2": "085",
        "admin_name3": "",
        "admin_code3": "",
        "latitude": "37.3814",
        "longitude": "-122.1258",
        "accuracy": "4"
    },
*/

?>