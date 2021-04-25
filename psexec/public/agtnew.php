<?php 
/** agtnew.php
    - mvc upper_agt.php, agtnew_form.php
    Create new name, thereafter direct to agtget.php for editing
*/

    // configuration
    require("../includes/config.php"); 

    // configuration SPECIAL, only Login can assess
    require("../includes/session_agt.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("upper_agt.php","agtnew_form.php",  ["title" => "New Name"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["place_name"]))
        {
            apologize("You must provide building name.");
        }
    
    //Check if similar Building name taken
    $results = CS50::query("
    SELECT * FROM  `builds` WHERE `place_name` = ? "
    , $_POST["place_name"]);

    // if no such name appear in library, insert new entry
    if (count($results) == 0)
    {
        //$rows = CS50::query("INSERT IGNORE INTO builds (place_name) VALUES(?)", $_POST["place_name"]);
        $rows = CS50::query("INSERT IGNORE INTO builds ( country_code,place_name) VALUES('SG',?)"
            , $_POST["place_name"]);
        $rows = CS50::query("INSERT IGNORE INTO places ( country_code,place_name) VALUES('SG',?)"
            , $_POST["place_name"]);
    }

        //dump($_POST); // DEBUG
        // redirect to EDIT page 
        $loc= "/agtget.php?geo=".$_POST["place_name"];
        redirect($loc);
    }

/** //dump($_POST); // DEBUG
    //print("dump\n "); dump($_POST); // DEBUG */
?>

