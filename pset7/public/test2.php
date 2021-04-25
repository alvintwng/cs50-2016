<!-- / https://www.w3schools.com/php/php_mysql_select.asp  
For Testing of PHP to SQL
-->

<?php
$servername = "localhost";
$username = "twng";
$password = "v1kCjsvLYytrBTGV";
$dbname = "pset7";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT id, symbol FROM portfolios ";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. " - Symbol: " . $row["symbol"]. "<br>";
    }
} else {
    echo "0 results";
}
$conn->close();
?>