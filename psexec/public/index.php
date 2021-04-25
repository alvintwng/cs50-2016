<?php

    //added by NgTW
    // configuration
    require("../includes/config.php"); 

    //start with listing
    require("../public/portfo_list.php");
    
    //dump($rows); // DEBUG
?>

<?php    
/** DIRECTORIES **
includes
├── config.php
├── helpers.php : functions for logout, lookup, apologize, dump, render
└── session_agt.php : glode id session only for user
public
├── agtdelete.php : select from scrolling name to delete, and update sql
├── agtentry.php : select from scrolling name to agtget.php
├── agtget.php : get sql data to list
├── agtnew.php : get new name and insert to sql
├── agtpost.php : post sql data from list
├── articles.php : not use
├── buildphoto : panoramic photos 
├── css
│ ├── bootstrap.min.css
│ └── styles.css : css
├── img
│ ├── ajax-loader.gif
│ ├── background.PNG : html background image
│ └── cs50property670x128.png : html header image
├── index.php : this page
├── js
│ ├── bootstrap.min.js
│ ├── jquery-1.11.3.min.js
│ ├── markerwithlabel_packed.js : google scripts for markers
│ ├── scripts.js: scripts for maps view and others
│ ├── scripts_pano.js : google panoramic views script
│ ├── typeahead.jquery.min.js
│ └── underscore-min.js
├── login.php : user login 
├── logout.php : user logout
├── portfo_list.php : gather list of properties
├── postpage.php : gather data for single property
├── search.php : search getGeo page, not use
├── student.php : full html page, so and so page
└── update.php : map's ne-sw update of google markers via script.js
views
├── agtdelete_form.php : mvc 3 of 4 html scrolling list of name
├── agtdone_form.php : mvc 3 of 4 html simple done page
├── agtentry_form.php : mvc 3 of 4 html scrolling list of name
├── agtget_form.php : mvc 3 of 4 html data to confirm
├── agtnew_form.php : mvc 3 of 4 html name for new entry
├── apology.php : mvc 3 of 4 html error page via helpers.php
├── dump.php : full html, not use, for debugging purposes
├── footer.php : mvc 4 of 4 html footer
├── header.php : mvc 1 of 4 html header
├── login_form.php : mvc 3 of 4 html user login page
├── portfo_form.php : mvc 3 of 4 html list of properties
├── postpage_form.php : mvc 3 of 4 html single data property with descriptn
├── upper.php : mvc 2 of 4 html google map
├── upper_agt.php : mvc 2 of 4 html user page
└── upstreetview.php : mvc 2 of 4 html panoramiv view
config.json : setup sql
*/
?>
