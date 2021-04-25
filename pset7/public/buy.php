<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must specify a stock to buy.");
        }
    }
    
    $stock = lookup($_POST["symbol"]); //return 'symbol", "name" & "price"
    
    if ($stock != 0 )
    {
        // if shares == 0
        if (empty($_POST["shares"]))
        {
            // else apologize
            apologize("You must specify a number of shares.");
        }

        //should be number, postitive buy and not fraction
        //See http://www.php.net/preg_match for details. 
        if (preg_match("/^\d+$/", $_POST["shares"]) == 0 )
        {
            apologize("Invalid number of shares.");
        }

        // convert stock symbol to upper case to stock
        //http://php.net/manual/en/function.mb-convert-case.php
        $_POST["symbol"] = mb_convert_case($_POST["symbol"], MB_CASE_UPPER);

        //check cash balance sufficient to buy   ???? CASH debit???
        $share_amt = $stock["price"] * $_POST["shares"];
        
        $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $row = $rows[0]; // first (and only) row
        
        if ($share_amt > $row["cash"] )
        {
            apologize("You can't afford that.");
        }

        //SQL, insert portfolio's share, check for duplicate, and update users'cash balance
        $results = CS50::query("
        INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) 
        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares);
        UPDATE users SET cash = cash - $share_amt WHERE id = ?
        ", $_SESSION["id"], $_POST["symbol"], $_POST["shares"], $_SESSION["id"] );

        //store the transaction, buysell = 0 for buy
        $history = CS50::query("
        INSERT INTO `pset7`.`history` (`user_id`, `buysell`, `datetime`, `symbol`, `shares`, `price`)
        VALUES (?, '0', CURRENT_TIMESTAMP, ?, ?, ?)"
        , $_SESSION["id"], $_POST["symbol"], $_POST["shares"], $stock["price"] );

        // redirect to portfolio
        redirect("/");
    }
    else
    {
        // else apologize
        apologize("Symbol not found.");
    }
?>

<!-- 
print("** dump ** " 
. $_POST["symbol"] 
." \$". $stock["price"]
." shares amt \$". $share_amt
." CASH BAL \$". $row["cash"]
     ); dump($rows); // DEBUG
-->