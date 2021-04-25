<?php

    // configuration
    require("../includes/config.php");

    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);

    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => (number_format($row["shares"], 0, '.', ',')),
                "symbol" => $row["symbol"],
                "total" => (number_format(($stock["price"]* $row["shares"]), 2, '.', ','))
                //http://php.net/manual/en/function.number-format.php
            ];
        }
    }

    $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
//dump($rows); //for checking array, debug
    $cash_format = number_format($rows[0]["cash"], 2, '.', ',');
    $cashs[0]=["cash" => ($cash_format) ];

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "cashs" => $cashs, "title" => "Portfolio"]);

?>

<!-- 
terminal:
killall -9 server
apache50 stop
mysql50 stop
browser: apache50 start ~/workspace/pset7/public
mysql50 start
browser: https://ide50-twng.cs50.io/phpmyadmin

Permissions
Folders: chmod 711 folder
Images, HTML, CSS, just: chmod 644 file
 users shouldn't execute an image!
Php: chmod 600 file
 users shouldn't see your Php code
Chmod 644 img/* js//*

dump($rows); //debug
staff: https://finance.cs50.net/.
-->