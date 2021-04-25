<!--
* header.php
  MVC with header.php xxx.php xxx.php footer.php

 A mashup of Google Maps with List of Propert Name.
-->

<!DOCTYPE html>

<html>
  <head>

        <!-- http://getbootstrap.com/ -->
        <link href="/css/bootstrap.min.css" rel="stylesheet"/>

        <!-- app's own CSS -->
        <link href="/css/styles.css" rel="stylesheet"/>

        <!-- https://developers.google.com/maps/documentation/javascript/ -->
        <script src="https://maps.googleapis.com/maps/api/js"></script>

        <!-- http://google-maps-utility-library-v3.googlecode.com/svn/tags/markerwithlabel/1.1.10/ -->
        <script src="/js/markerwithlabel_packed.js"></script>

        <!-- http://jquery.com/ -->
        <script src="/js/jquery-1.11.3.min.js"></script>

        <!-- http://getbootstrap.com/ -->
        <script src="/js/bootstrap.min.js"></script>

        <!-- http://underscorejs.org/ -->
        <script src="/js/underscore-min.js"></script>

        <!-- https://github.com/twitter/typeahead.js/ -->
        <script src="/js/typeahead.jquery.min.js"></script>

        <!-- was title>Mashup</title -->

        <?php if (isset($title)): ?>
            <title>CS50 Building: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>CS50 Building</title>
        <?php endif ?>
        
  </head>
  <body>
    <div class="container">
      <table style="width: 100%; height: 100%;">
        <tr style="height: 120px">
          <td>
              <div id="top">
                <a href="/"><img alt="CS50 Building" src="/img/cs50property670x128.png"/></a>
              </div>
          </td>
        </tr>
        
<!--

-->