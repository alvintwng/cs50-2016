<?php 
/** agtentry.php
    - Enter place: agtentry (mvc upper_agt + agtentry_form)
    . if available go to Edit agtget.php?geo=
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
        // render form
        render("upper_agt.php","agtentry_form.php",  ["positions" => $positions, "title" => "Edit"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["place_name"]))
        {
            apologize("You must select a property to edit.");
        }
    
    // Check if similar Building name taken..  ?? may not happen?
    $results = CS50::query("
    SELECT * FROM  `builds` WHERE `place_name` = ? "
    , $_POST["place_name"]);

    if (count($results) == 0)
    {
        apologize("No such name in the library.");
    }

        // redirect to EDIT or DELETE ? 
        $loc= "/agtget.php?geo=".$_POST["place_name"];
        redirect($loc);
    }

/** print("dump\n "); dump($_POST); // DEBUG */
?>