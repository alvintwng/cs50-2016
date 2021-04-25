<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("setpassword_form.php", ["title" => "Reset Password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO - done

        // validate submission
        if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        
        // if password different from confirmation
        else if ( ($_POST["password"]) != ($_POST["confirmation"]))
        {
            apologize("Your password is different from confirmation.");
        }
        
        // sql, update new password for user
        $RESULT = CS50::query("UPDATE users SET hash = ? WHERE id = ?"
        , password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"] );

        // redirect to portfolio
        //print("dump\n "); dump(); // DEBUG
        redirect("/");

        // else apologize
        apologize("error in password.");
    }

?>
