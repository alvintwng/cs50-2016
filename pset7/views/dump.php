<!DOCTYPE html>

<html>

    <head>
        <title>dump</title>
    </head>

    <body>
        <?php for ($i = 0, $n = count($arguments); $i < $n; $i++): ?>
            <pre><?php print_r($arguments[$i]); ?></pre>
            <?php if ($i < $n - 1): ?>
                <hr/> 
            <?php endif ?>
        <?php endfor ?>
    </body>

</html>
<!-- 
example at index.php:
dump(CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"] ) );// DEBUG

output:
Array
(
    [0] => Array
        (
            [id] => 4
            [user_id] => 11
            [symbol] => AAPL
            [shares] => 300
        )

)
-->