<?php
    // configuration
    require("../includes/config.php"); 
    
    require("../views/header.php"); 
?>
</table>

<table style="width:100%">
  <tr>
  	<td style="width:25%"></td>
  	<td style="width:50%">
      <div id="middle" style="text-align: left">

<h2>
<ul>
    <li>CS50 2016 FINAL PROJECT</li>
    <li>Title: CS50 Property</li>
    <li>Student Name: Ng Teck Wee</li>
    <li>Country: Singapore</li>
    <li>Description: 
    <ul>
      <li>
      This website is to show the list of properties for sale, and icons on the map.</li>
      <li>Upon selection, will direct to single sale page, whereby it shown the paronomic view of the unit, 
      and brief description.</li>
      <li>There also login session for new entry, edting or delete.</li>
      </ul>
    </li>
  
</ul>
</h2>

<br><br><br><br><br><br><br>
<p>To prepare schedule of video clip</p>
<ul>
    <li>1. ready all screens; CS50IDE, webpage, phppage in 1 full screen </li>
    <li>2. Start with Introduction page of student, this page </li>
    <li>3. Index page: map zooming, paning </li>
    <li>4. Scroll to listing, and pulse </li>
    <li>5. Posting Page: Paroramic view, compass, zoom, full screen, scroll down </li>
    <li>6. Back to index/map, select icon Brooks, and manipulate </li>  
    <li>7. Login Page: monkey proof via clicking and wrong passwords</li>  
    <li>8. New Page: foolProof, in data, and done.  Back to index and check </li> 
    <li>9. Edit Page: Full proof, edit and done, and edit to show</li>
    <li>A. DELETE Page: Full proof, delete and done. Check to Delete</li>  
    <li>B. Logout, back to Index.  </li>
    <li>C. Back to student page</li>  
    <li>D. Click thru IDE, myPHP, Back to student page</li>
    <li>E. Upload to YouTube: now https://youtu.be/fRVdOQHeC7Q</li>  
</ul>

<!-- some info from www
If you just want to throw the contents of the file onto the screen you can try using PHP.
?php
    $myfilename = "../log.txt";
    if(file_exists($myfilename)){
      echo file_get_contents($myfilename);
    }
?-->

  </div>
    </td>
      <td style="width:25%"></td>
    </tr>
  <div>

<?php  
    require("../views/footer.php"); 
?>
