<?php 
/** agtdelete.php
    To delete row, MVC with upper_agt.php & agtdelete_form.php,
    if done, MVC to upper_agt.php","agtdone_form.php
    eg. https://ide50-twng.cs50.io/agtdelete.php?geo=Small%20Project
*/
    // configuration
    require("../includes/config.php"); 

    // configuration SPECIAL, only Login can assess
    require("../includes/session_agt.php"); 

    $rows = CS50::query("SELECT place_name FROM builds WHERE user_id = ?", $_SESSION["id"]);
    if (count($rows) == 0)
    {
            apologize("Nothing to sell.");
    }

    // list the available stocks
    $positions = [];
    foreach ($rows as $row)
    {
        //was $stock = lookup($row["place_name"]);
        //was if ($stock !== false) {
            $positions[] = [ "place_name" => $row["place_name"] ]; //}
    }

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("upper_agt.php","agtdelete_form.php", ["positions" => $positions, "title" => "Delete"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {

        // validate submission
        if (empty($_POST["place_name"]))
        {
            apologize("You must select a property to delete.");
        }
        
        //printf($_POST["place_name"]);dump($positions); // DEBU    
        //Delete on Property name
        $results = CS50::query("DELETE FROM `psexec`.`builds` WHERE `builds`.`place_name` = ? ", $_POST["place_name"]);
        $results = CS50::query("DELETE FROM `psexec`.`places` WHERE `places`.`place_name` = ? ", $_POST["place_name"]);
        //show Done page
        render("upper_agt.php","agtdone_form.php",  ["title" => "User"]);
    }
    
    // else apologize
    apologize("Name not found.");

/** dump($rows); // DEBUG
dump($positions); // DEBUG */
?>