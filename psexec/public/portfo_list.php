<?php
    // portfo_list.php
    // To list out all row
    // mvc upper.php, portfo_form.php
    
    // configuration
    //require("../includes/config.php"); 

    //$rows = CS50::query("SELECT * FROM builds WHERE country_code = 'SG'"); // WORK!
    $rows = CS50::query("SELECT * FROM builds JOIN places ON builds.place_name 
        = places.place_name  WHERE places.country_code = 'SG'"); // WORK!

    $positions = [];
    foreach ($rows as $row)
    {
            $positions[] = [
                "postal_code" => $row["postal_code"],
                "place_name" => $row["place_name"],
                "admin_name1" => $row["admin_name1"],
                "admin_name2" => $row["admin_name2"],
                "admin_name3" => $row["admin_name3"],
                "img_name" => $row["img_name"],
                "building" => $row["building"],
                "yearstart" => $row["yearstart"],
                "freelease" => $row["freelease"],
                "sqft" => $row["sqft"],
                "bedroom" => $row["bedroom"],
                "shower" => $row["shower"],
                "price" => (number_format($row["price"], 0, '.', ',')),
                "psf" => (number_format(($row["price"]/$row["sqft"]), 2, '.', ',')),
                //http://php.net/manual/en/function.number-format.php
            ];
    } 

    //dump($rows); // DEBUG 
    render("upper.php","portfo_form.php", ["positions" => $positions, "title" => "Map"]);
    
/*
SELECT users.fullname, moms.mother FROM users
JOIN moms ON users.username = moms.username

SELECT * FROM builds JOIN places ON builds.place_name = places.place_name  WHERE places.country_code = 'SG'
results: ok

was:
Marina One
Condominium
7 Straits View
3 bedroom, 5 shower 
built 2017 99years Leasehold
1518 sqft | S$2,195.65 psf 
S$3,333,000 

*/
    
?>

<!--

 dump($rows); // DEBUG

-->