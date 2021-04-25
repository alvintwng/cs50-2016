<?php

    require(__DIR__ . "/../includes/config.php");
    
    // ensure proper usage
    if (empty($_GET["geo"]))
    {
        http_response_code(400);
        exit;
    }
    
    //echo 'myGetGeo : ' . $_GET["geo"]; //DEBUG
    
    // TODO: search database for places matching $_GET["geo"], store in $places
    //$rows = CS50::query("SELECT * FROM places WHERE postal_code = ?", $_GET["geo"]); // ok
    //$rows = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name) AGAINST (?)", 
    //    $_GET["geo"]); // after create new index, index_place_postal.
    $rows = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name, admin_name1, admin_name2) 
        AGAINST (?)", $_GET["geo"]); // after amend index_place_postal.
    
    // numerically indexed array of places
    $places = [];
    
    // iterate over items in channel
    foreach ($rows as $row)
    {
        // add data to array
        $places[] = [
            "id" => $row["id"],
            "country_code" => $row["country_code"],
            "postal_code" => $row["postal_code"],
            "place_name" => $row["place_name"],
            "admin_name1" => $row["admin_name1"],
            "admin_code1" => $row["admin_code1"],
            "admin_name2" => $row["admin_name2"],
            "admin_code2" => $row["admin_code2"],
            "admin_name3" => $row["admin_name3"],
            "admin_code3" => $row["admin_code3"],
            "latitude" => $row["latitude"],
            "longitude" => $row["longitude"],
            "accuracy" => $row["accuracy"]

        ];
    }

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));


/*
To test search.php, even before your text box is operational, simply visit URLs like
https://ide50-twng.cs50.io/search.php?geo=Cambridge,Massachusetts,US
https://ide50-twng.cs50.io/search.php?geo=Cambridge,+Massachusetts
https://ide50-twng.cs50.io/search.php?geo=Cambridge,+MA
https://ide50-twng.cs50.io/search.php?geo=Cambridge+MA
https://ide50-twng.cs50.io/search.php?geo=02138
or
https://ide50-twng.cs50.io/search.php?geo=New+Haven,Connecticut,US
https://ide50-twng.cs50.io/search.php?geo=New+Haven,+Massachusetts
https://ide50-twng.cs50.io/search.php?geo=New+Have,+MA
https://ide50-twng.cs50.io/search.php?geo=New+Haven+MA
https://ide50-twng.cs50.io/search.php?geo=06511

screen output example as follow:
[
    {
        "id": "15636",
        "country_code": "US",
        "postal_code": "02138",
        "place_name": "Cambridge",
        "admin_name1": "Massachusetts",
        "admin_code1": "MA",
        "admin_name2": "Middlesex County",
        "admin_code2": "017",
        "admin_name3": "",
        "admin_code3": "",
        "latitude": "42.3770",
        "longitude": "-71.1256",
        "accuracy": "4"
    }
]

*/

/*
at js/scripts.js

    $.getJSON("search.php", parameters)
    .done(function(data, textStatus, jqXHR) {
*/

?>