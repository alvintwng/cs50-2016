<?php

    // configuration
    require("../includes/config.php"); 

    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);

    $positions = [];
    foreach ($rows as $row)
    {
        if ($row["buysell"]) // 1 sell
        {
            $transact = "SELL";
        }
        else  // 0 buy
        {
            $transact = "BUY";
        }
        
            $positions[] = [
                "transact" => $transact,
                "datetime" => $row["datetime"],
                "symbol" => $row["symbol"],
                "shares" => (number_format($row["shares"], 0, '.', ',')),
                "price" => (number_format($row["price"], 2, '.', ','))
                //http://php.net/manual/en/function.number-format.php
            ];
    } 
    // render portfolio
    render("history_form.php", ["positions" => $positions, "title" => "History"]);

?>

<!--
"buysell" => $row["buysell"]

 dump($rows); // DEBUG
-->