<?php
/** search.php
 * for debug
 *  THIS PAGE NOT USE YET, had copy to postpage.php */

    require(__DIR__ . "/../includes/config.php");
    
    // ensure proper usage
    if (empty($_GET["geo"]))
    {
        http_response_code(400);
        exit;
    }
    
    echo 'myGetGeo : ' . $_GET["geo"]; //DEBUG

    // TODO: search database for places matching $_GET["geo"], store in $positions
    $rows = CS50::query("SELECT * FROM builds WHERE MATCH(postal_code, place_name, admin_name1)
    AGAINST (?)", $_GET["geo"]); // after amend Myindex to FULLTEXT.
    
    // numerically indexed array of location
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

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($positions, JSON_PRETTY_PRINT));

/**  after amend mySQL/builds/Myindex to FULLTEXT.
tested ok: https://ide50-twng.cs50.io/search.php?geo=Trilinq
*/
?>