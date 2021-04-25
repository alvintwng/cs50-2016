<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
    }
    
    $stock = lookup($_POST["symbol"]);
    
    if ($stock != 0 )
    {
        // report price
        //See format, http://php.net/manual/en/function.number-format.php for details.
        $english_format_number = number_format($stock["price"], 2, '.', '');
        $message[0]=("A share of {$stock["name"]} ({$stock["symbol"]}) costs ");
        $message[1]=(" \${$english_format_number}.\n");

        //$message=("A share of {$stock["name"]} ({$stock["symbol"]}) costs \${$english_format_number}.\n");
        render("quote_view.php", ["message" => $message]);

    }
    else
    {
        // else apologize
        apologize("Symbol not found.");
    }

?>
