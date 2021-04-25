<!-- * agtpost.php
    To update data, collected from agtget.php
    from agtget.php
-->

<!DOCTYPE html>

<html>
    <head>

        <!-- app's own CSS ** need this for map!-->
        <link href="/css/styles.css" rel="stylesheet"/ -->

        <!-- https://developers.google.com/maps/documentation/javascript/  ** need this for map!
        <script src="https://maps.googleapis.com/maps/api/js"></script> -->

        <!-- http://jquery.com/  ** need this for map!-->
        <script src="/js/jquery-1.11.3.min.js"></script>

        <!-- app's own JavaScript  ** need this for map!
        <script src="/js/scripts.js"></script>-->

        <title>Property Entry</title>

    </head>
    <body>
<?php 
    // configuration
    require("../includes/config.php"); 

    // configuration SPECIAL, only Login can assess
    require("../includes/session_agt.php"); 

    //dump($_POST); // DEBUG

    // else if user reached page via POST (as by submitting a form via POST)
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["place_name"]))
        {
            apologize("You must provide building name.");
        }

// query database for places
        $rows = CS50::query("UPDATE places SET 
          postal_code = (?)
        , admin_name1 = (?)
        , admin_name2 = (?)

        , latitude = (?)
        , longitude = (?)
        , accuracy = (4)
        WHERE place_name = (?)"
        , $_POST["postal_code"]
        , $_POST["admin_name1"]
        , $_POST["admin_name2"]

        , $_POST["latitude"]
        , $_POST["longitude"]
        , $_POST["place_name"]);


        // query database for builds
        $rows = CS50::query("UPDATE builds SET 
          postal_code = (?)
        , admin_name1 = (?)
        , admin_name2 = (?)

        , img_name = (?)
        , building = (?)
        , latitude = (?)
        , longitude = (?)
        , yearstart = (?)
        
        , freelease = (?)
        , sqft = (?)
        , bedroom = (?)
        , shower = (?)
        , price = (?)
        , description = (?)
        WHERE place_name = (?)"
        , $_POST["postal_code"]
        , $_POST["admin_name1"]
        , $_POST["admin_name2"]

        , $_POST["img_name"]
        , $_POST["building"]
        , $_POST["latitude"]
        , $_POST["longitude"]
        , $_POST["yearstart"]
        
        , $_POST["freelease"]
        , $_POST["sqft"]
        , $_POST["bedroom"]
        , $_POST["shower"]
        , $_POST["price"]
        , $_POST["description"]
        , $_POST["place_name"]);

        //print("dump\n "); dump($_POST); // DEBUG

        //Show done
        render("upper_agt.php","agtdone_form.php",  ["title" => "User"]);
    }
?>

    </body>
</html>
