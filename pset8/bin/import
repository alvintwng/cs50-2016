#!/usr/bin/env php
<?php

    // TODO
    /*
    To run this script, you’ll want to execute a command like
        ./import /path/to/US.txt
    where /path/to/US.txt is indeed the (relative or absolute) path to that file.
    
    TRUNCATE places
    in phpMyAdmin’s SQL tab or by clicking Empty the table (TRUNCATE) in phpMyAdmin’s Operations tab.

    ~/workspace/pset8/bin/ $ ./import
    Usage: import file
    ~/workspace/pset8/bin/ $ ./import ~/workspace/mydata.txt
    2 rows added.
    ~/workspace/pset8/bin/ $ 
    */

?>

<?php
// configuration
    require("../includes/config.php");


    // ensure proper usage
    if ($argc != 2) {
        print("Usage: import file\n");
        exit(1);
    }

    // $filename
    $filename = $argv[1];
    
    //check if file is true;
    if (is_readable($filename) == FALSE){
        print("The file is not readable!\n");
        exit(1);
    } 


    $row = 0;
    if (($handle = fopen($filename, "r")) !== FALSE) {
        while (($data = fgetcsv($handle, 1000, "\t")) !== FALSE) {
            $num = count($data);
            $row++; //count row
            
        //query database for data import
        $rows = CS50::query("INSERT INTO `pset8`.`places` (`country_code`, `postal_code`, `place_name`, 
        `admin_name1`,`admin_code1`,`admin_name2`, `admin_code2`, `admin_name3`, `admin_code3`, `latitude`, 
        `longitude`, `accuracy`)  VALUES(?, ?, ?, ?, ?, ?  ,?, ?, ?, ?, ?, ?)" , $data[0], $data[1], $data[2], 
        $data[3], $data[4], $data[5], $data[6], $data[7], $data[8], $data[9], $data[10],$data[11] );
        
        }
        fclose($handle);
        
        //echo to terminal
        echo "$row rows added.\n";
}



/*
$row = 1;
if (($handle = fopen($filename, "r")) !== FALSE) {
    while (($data = fgetcsv($handle, 100, "\t")) !== FALSE) {
        $num = count($data);
        echo "<p> $num fields in line $row: <br /></p>\n";
        $row++;
        echo "'" . $data[0] . "'";
        for ($c=1; $c < $num; $c++) {
            echo ", '" . $data[$c] . "'"; 
        }
        echo "\n"

// specify allowed field delimiters
    $delimiters = array(
        'comma'     => ',',
        'semicolon' => ';',
        'tab'         => "\t",
        'pipe'         => '|',
        'colon'     => ':'
    );
    
    // specify allowed line endings
    $line_endings = array(
        'rn'         => "\r\n",
        'n'         => "\n",
        'r'         => "\r",
        'nr'         => "\n\r"
    );

*/
?>

