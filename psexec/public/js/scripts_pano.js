/* global google */
/* global _ */
/**
 * scripts_pano.js
 * used on /views/upstreetview.php
 * TWNg
 *
 */

// get panoramic images from innderHTML, eg document.getElementById("demo").innerHTML = 
//var myPlaceN = document.getElementById("placen");
//"The text from the intro paragraph is " + myElement.innerHTML;

// imgn - panoramic images from innderHTML,
var imgcontent = '/buildphoto/' + document.getElementById("imgn").innerHTML;
//for debugging - var imgcontent = '/buildphoto/38eightriversuites.JPG'; 

// placen - descrition
var imgdes     = '360 views of ' + document.getElementById("placen").innerHTML;
//for debugging - var imgdes     = 'imgdes The Springside - TX showsuite';

// view direction
var imgheading = 00;


// execute when the DOM is fully loaded
$(function() {

initPano();

});



/**
 * panoviews of reception
 * TWNg
 */
function initPano() {
    var panorama = new google.maps.StreetViewPanorama(
      document.getElementById('map-pano'), {
        pano: 'reception',
        visible: true,
        panoProvider: getCustomPanorama
    });
}

// Return a pano image given the panoID.
function getCustomPanoramaTileUrl(pano, zoom, tileX, tileY) {
    return imgcontent;
}

// Construct the appropriate StreetViewPanoramaData given
// the passed pano IDs.
function getCustomPanorama(pano, zoom, tileX, tileY) {
    if (pano === 'reception') {
      return {
        location: {
          pano: 'reception',
          description: imgdes
        },
        links: [],
        // The text for the copyright control.
        copyright: 'Imagery (c) 2010 Google',
        // The definition of the tiles for this panorama.
        tiles: {
          tileSize: new google.maps.Size(1024, 512),
          worldSize: new google.maps.Size(1024, 512),
          // The heading in degrees at the origin of the panorama
          // tile set.
          centerHeading: imgheading,
          getTileUrl: getCustomPanoramaTileUrl
        }
      };
    }
}



