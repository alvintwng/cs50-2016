<?php
    // postpage.php
    // Show single page of property
    // mvc upstreetview.php, postpage_form.php
    
    // configuration
    require("../includes/config.php"); 

    //$rows = CS50::query("SELECT * FROM builds WHERE country_code = 'SG'"); // WORK!

    // ensure proper usage
    if (empty($_GET["geo"]))
    {
        http_response_code(400);
        exit;
    }
    //echo 'myGetGeo : ' . $_GET["geo"]; //DEBUG

    // Search database for place_name matching $_GET["geo"], store in $rows
    //$rows = CS50::query("SELECT * FROM builds WHERE MATCH(postal_code, place_name, admin_name1)
    //AGAINST (?)", $_GET["geo"]); // after amend Myindex to FULLTEXT.
    $rows = CS50::query("SELECT * FROM builds JOIN places ON builds.place_name = places.place_name
        WHERE MATCH(builds.postal_code, builds.place_name, builds.admin_name1)
        AGAINST (?)", $_GET["geo"]);

    // show paranomic view, and detail view
    $perlist = $rows[0];    
    //dump($perlist); // DEBUG
    render("upstreetview.php","postpage_form.php", ["perlist" => $perlist, "title" =>  $perlist["place_name"]]);


/*
tested ok: https://ide50-twng.cs50.io/postpage.php?geo=Amber
 dump($rows); // DEBUG

tested: /postpage.php?geo=Marina%20One
was: $rows = CS50::query("SELECT * FROM builds WHERE country_code = 'SG'"); 
SELECT * FROM builds JOIN places ON builds.place_name = places.place_name  WHERE places.country_code = 'SG'

*/
?>