<?php
/** agtget.php
    To show and edit data in form
    - mvc agtget + agtget_form => post to agtpost.php
    eg https://ide50-twng.cs50.io/agtget.php?geo=Marina%20One
*/

    // configuration
    require("../includes/config.php"); 

    // configuration SPECIAL, only Login can assess
    require("../includes/session_agt.php"); 

    // ensure proper usage
    if (empty($_GET["geo"]))
    {
        http_response_code(400);
        exit;
    }
    //echo 'myGetGeo : ' . $_GET["geo"]; //DEBUG

    // Search database for places matching $_GET["geo"], store in $result. It work after amend Myindex to FULLTEXT.
    $result = CS50::query("SELECT * FROM builds WHERE place_name = (?)",  $_GET["geo"]);
    //$result = CS50::query("SELECT * FROM builds JOIN places ON builds.place_name = places.place_name
    //    WHERE places.place_name = (?)",  $_GET["geo"]);

    if (count($result) == 0)
    {
        // else apologize
        apologize("Wrong Name!");
    }
    
    // store the first row, and mvc to form
    //dump($result); // DEBUG
    $perlist = $result[0];    
    render("upper_agt.php","agtget_form.php",  ["perlist" => $perlist, "title" => "Edit"]);

/**
tested ok: https://ide50-twng.cs50.io/postpage.php?geo=Amber

    dump($rows); // DEBUG
*/
?>