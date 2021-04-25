<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    if (count($rows) == 0)
    {
            apologize("Nothing to sell.");
    }

    // list the available stocks
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [ "symbol" => $row["symbol"] ];
        }
    }

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_form.php", ["positions" => $positions, "title" => "Sell"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must select a stock to sell.");
        }

        //determine the cash amount to be add
        $rows = CS50::query("
        SELECT  `shares` FROM  `portfolios` WHERE  `user_id` =? AND `symbol` =  ? "
        , $_SESSION["id"],$_POST["symbol"] );
        
        // if we found user, check password
        if (count($rows) != 1)
        {
            apologize("Error in more rows of share.");
        }
        // first (and only) row
        $row = $rows[0];

        //share prices, lookup() return 'symbol", "name" & "price"
        $stock = lookup($_POST["symbol"]);

        //calculate anmount to debit
        $tamount = ( $row["shares"] * $stock["price"] );
        
        //remove selected stock, and update amount to CASH
        $results = CS50::query("
        UPDATE users SET cash = cash + $tamount WHERE id = ?;
        DELETE FROM `portfolios` WHERE  `user_id` =? AND `symbol` =  ?
        ", $_SESSION["id"], $_SESSION["id"],$_POST["symbol"] );

        //store the transaction, buysell = 1 for sell
        $history = CS50::query("
        INSERT INTO `pset7`.`history` (`user_id`, `buysell`, `datetime`, `symbol`, `shares`, `price`)
        VALUES (?, '1', CURRENT_TIMESTAMP, ?, ?, ?)"
        , $_SESSION["id"], $_POST["symbol"], $row["shares"], $stock["price"] );

        // redirect to portfolio
        redirect("/");
    }
    
    // else apologize
    apologize("Symbol not found.");

?>

<!-- 
dump($rows); // DEBUG
-->