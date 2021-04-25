<!--
* upstreetview.php
panoramic view of panorami photo taken, goes with scripts_pano.js
require mvc header.php, this upstreetview.php, postpage_form.php & footer.php
drive from postpage.php

eg https://ide50-twng.cs50.io/postpage.php?geo=The%20Brooks%20I
-->
        <tr>
          <td >
            <h1 id="placen"><?php print("$perlist[place_name] ");  ?></h1>
            <div style="text-align: left" class="text-muted small" 
              id="imgn"><?php print("$perlist[img_name]");  ?></div>
            </td>
        </tr>
        
        <tr style="height: 400px">
          <td >
            <!-- fill viewport -->
            <div class="container-fluid">

                <!-- app's own JavaScript -->
                <script src="/js/scripts_pano.js"></script>
        
                <!-- https://developers.google.com/maps/documentation/javascript/tutorial -->
                <div id="map-pano"></div>

            </div>
          </td>
        </tr>
        
       
        <div id="middle">
          
                
<!--<p>This example demonstrates the <b>getElementById</b> method!</p>
<p id="demo"></p>
 script>
var myElement = document.getElementById("test1");
document.getElementById("demo").innerHTML = 
"The text from the intro paragraph is " + myElement.innerHTML;
</script -->