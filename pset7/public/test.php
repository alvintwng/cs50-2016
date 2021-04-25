<p>Simple test for printing the SQL data</p>

<table>

<?php
    // configuration
    require("../includes/config.php");
    
    $results = CS50::query("SELECT symbol FROM portfolios ");
    
    if ( $results !== false )
    {
        foreach ( $results as $result)
        {
            print("<tr><td>> " . $result['symbol'] . "<//td></tr>");
        }
    }
?>

</table>

<!--

$results = CS50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);

-->