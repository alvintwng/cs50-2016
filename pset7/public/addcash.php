<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("addcash_form.php", ["title" => "Add Cash"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["cashin"]))
        {
            apologize("You must specify cash to add.");
        }

        //should be number, postitive buy and not fraction
        //See http://www.php.net/preg_match for details. 
        if (preg_match("/^\d+$/", $_POST["cashin"]) == 0 )
        {
            apologize("Invalid number of cash.");
        }

        $cashin = $_POST["cashin"];

        //update amount to sql CASH
        $results = CS50::query("
        UPDATE users SET cash = cash + $cashin WHERE id = ?
        ", $_SESSION["id"] );

        // redirect to portfolio
        redirect("/");

    }
    else
    {
        // else apologize
        apologize("Cash not found.");
    }

?>
