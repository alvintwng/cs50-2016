/* global google */
/* global _ */
/**
 * scripts.js
 *
 * Computer Science 50
 * Problem Set 8
 *
 * Global JavaScript.
 */
 
/** function:
 * $(function()
 * addMarker(place)
 * articles(marker, query)
 * configure()
 * hideinfo()
 * mqfire(country)
 * mqUrl()
 * mqtime()
 * removeMarkers()
 * search(query, cb)
 * showInfo(marker, content)
 * update()
 * listAllProperties(o)
 */ 

// Google Map
var map;

// markers for map
var markers = [];

// info window
var info = new google.maps.InfoWindow();

// set macquee places for articles, via TWNg
var country = "us"; //

// execute when the DOM is fully loaded
$(function() {

    // styles for map
    // https://developers.google.com/maps/documentation/javascript/styling
    var styles = [

        // hide Google's labels
        {
            featureType: "all",
            elementType: "labels",
            stylers: [
                {visibility: "off"}
            ]
        },

        // hide roads
        {
            featureType: "road",
            elementType: "geometry",
            stylers: [
                {visibility: "off"}
            ]
        }
    ];

    // options for map
    // https://developers.google.com/maps/documentation/javascript/reference#MapOptions
    var options = {
        center: {lat: 37.4236, lng: -122.1619}, // Stanford, California
        //center: {lat: 41.3184, lng: -72.9318}, // New Haven, US
        //center: {lat: 42.3770, lng: -71.1256}, // Cambridge, US
        disableDefaultUI: true,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        maxZoom: 14,
        panControl: true,
        styles: styles,
        zoom: 13,
        zoomControl: true
    };

    // get DOM node in which map will be instantiated
    var canvas = $("#map-canvas").get(0);

    // instantiate map
    map = new google.maps.Map(canvas, options);

    // configure UI once Google Map is idle (i.e., loaded)
    google.maps.event.addListenerOnce(map, "idle", configure);

});


/**
 * Adds marker for place to map.
 */
function addMarker(place)
{
    // TODO //listAllProperties(place); // for DEBUG

    // marker's icon image // http://www.lass.it/Web/viewer.aspx?id=4
    var image = 'https://maps.google.com/mapfiles/kml/pal3/icon31.png'; 

    var myLatLng = {
        lat: Number(place.latitude), // 1* is to convert to integer
        lng: Number(place.longitude)
    };

    var marker = new MarkerWithLabel({
       position: myLatLng,
       draggable: false, // was true
       raiseOnDrag: true,
       map: map,
       icon: image,
       labelContent: (place.place_name) + ', ' + (place.admin_name1),
       labelAnchor: new google.maps.Point(22, 0),
       labelClass: "label", // the CSS class for the label, styles.css:50
       //labelStyle: {opacity: 1.00}
    });
    markers.push(marker); //  push to the array.

    google.maps.event.addListener(marker, 'click', function() {
        // get the news articles in info windows
        articles(marker, place.country_code+",+"+place.place_name+",+"+place.admin_name1+",+"+place.admin_name2 );
        //articles(marker, place.country_code+",+"+place.postal_code ); //postal code dont work for outside US
        //console.log('#place :' + place.place_name); //DEBUG
    });
}


/**
 * Searches database for news articles, and out to window.
 * by NgTW
 */
function articles(marker, query)
{
    var content = '<div id = "info"><ul>'; // start of ordered list
    
    // get places matching articles (asynchronously)
    var parameters = {
        geo: query      //eg geo: (Cambridge,+Massachusetts)
    };
    
    // get news articles, and add to 
    $.getJSON("articles.php", parameters)
    .done(function(data, textStatus, jqXHR) {
        for (var i = 0; i < data.length; i++)
        {
            content += ('<li><a href ="'+data[i].link+'" target="_blank">'+data[i].title+'</a></li>' ); 
        }
        content += "</ul></div>";  // console.log(content); //  DEBUG
        
        showInfo(marker, content);
    })
    
    .fail(function(jqXHR, textStatus, errorThrown) {

        // log error to browser's console
        console.log(errorThrown.toString());
    });
}


/**
 * Configures application.
 */
function configure()
{
    // update UI after map has been dragged
    google.maps.event.addListener(map, "dragend", function() {
        update();
    });

    // update UI after zoom level changes
    google.maps.event.addListener(map, "zoom_changed", function() {
        update();
    });

    // remove markers whilst dragging
    google.maps.event.addListener(map, "dragstart", function() {
        removeMarkers();
    });

    // configure typeahead
    // https://github.com/twitter/typeahead.js/blob/master/doc/jquery_typeahead.md
    $("#q").typeahead({
        autoselect: true,
        highlight: true,
        minLength: 1
    },
    {
        source: search,
        templates: {
            empty: "no places found yet",
            //suggestion: _.template("<p>TODO</p>")
            suggestion: _.template("<p><%- place_name %>, <%- admin_name1 %></p>")
        }
    });

    // re-center map after place is selected from drop-down
    $("#q").on("typeahead:selected", function(eventObject, suggestion, name) {

        // ensure coordinates are numbers
        var latitude = (_.isNumber(suggestion.latitude)) ? suggestion.latitude : parseFloat(suggestion.latitude);
        var longitude = (_.isNumber(suggestion.longitude)) ? suggestion.longitude : parseFloat(suggestion.longitude);

        // set map's center
        map.setCenter({lat: latitude, lng: longitude});

        // update UI
        update();
    });

    // hide info window when text box has focus
    $("#q").focus(function(eventData) {
        hideInfo();
    });

    // re-enable ctrl- and right-clicking (and thus Inspect Element) on Google Map
    // https://chrome.google.com/webstore/detail/allow-right-click/hompjdfbfmmmgflfjdlnkohcplmboaeo?hl=en
    document.addEventListener("contextmenu", function(event) {
        event.returnValue = true; 
        event.stopPropagation && event.stopPropagation(); 
        event.cancelBubble && event.cancelBubble();
    }, true);

    // update UI
    update();

    // update macquee, via TWNg
    //mqfire(country); // places for articles, transfered to update()
    
    // continue update the date and time at macquee
    var nIntervId;
    nIntervId = setInterval(mqtime, 1000); //kept the time running

    // give focus to text box
    $("#q").focus();
}

/**
 * Hides info window.
 */
function hideInfo()
{
    info.close();
}


/**
 * macquee: gather articles and add to content for macquee.
 * via TWNg
 */
function mqfire(country)
{
    var content = ' ';
    var numberNews = 5; // number of news
    
    // get places matching articles (asynchronously)
    var parameters = {
        geo: country      //eg geo: (Cambridge,+Massachusetts)
    };
    
    // get news articles, and add to 
    $.getJSON("articles.php", parameters)
    .done(function(data, textStatus, jqXHR) {
    
        if (data.length < numberNews)
            { count = data.length }
        else
            {count = numberNews}
    
        for (var i = 0; i < count; i++)
        {   content += data[i].title.substring(0, 50) + " . . . " ;} // trim to short sentences
        content += " . . . ";  //console.log(content); //  DEBUG
    
        var text02 = content;
        document.getElementById("mqtext2").innerHTML = country + ': ' + text02 ; // use js format
    })
}

/**
 * macquee on click to bring out href
 */
function mqUrl()
{
    var mqUrl = "http://news.google.com/news?geo=" + country ;
    window.open(mqUrl);
}

/**
 * macquee on date and time
 */
function mqtime()
{
    text01 = Date();
    //console.log('time'); //  DEBUG
    mqtext1.textContent = text01 + ' . . . ';
}


/**
 * Removes markers from map.
 */
function removeMarkers()
{
    // TODO
    // Deletes all markers in the array by removing references to them.
    for (var i = 0; i < markers.length; i++)
    {
        markers[i].setMap(null);
    }
    markers = [];
}

/**
 * Searches database for typeahead's suggestions.
 */
function search(query, cb)
{
    // get places matching query (asynchronously)
    var parameters = {
        geo: query
    };
    $.getJSON("search.php", parameters)
    .done(function(data, textStatus, jqXHR) {

        // call typeahead's callback with search results (i.e., places)
        cb(data);
    })
    .fail(function(jqXHR, textStatus, errorThrown) {

        // log error to browser's console
        console.log(errorThrown.toString());
    });
}

/**
 * Shows info window at marker with content.
 */
function showInfo(marker, content)
{
    // start div
    var div = "<div id='info'>";
    if (typeof(content) === "undefined")
    {
        // http://www.ajaxload.info/
        div += "<img alt='loading' src='img/ajax-loader.gif'/>";
    }
    else
    {
        div += content;
    }

    // end div
    div += "</div>";

    // set info window's content
    info.setContent(div);

    // open info window (if not already open)
    info.open(map, marker);
}

/**
 * Updates UI's markers.
 */
function update() 
{
    // get map's bounds
    var bounds = map.getBounds();
    var ne = bounds.getNorthEast();
    var sw = bounds.getSouthWest();

    // get places within bounds (asynchronously)
    var parameters = {
        ne: ne.lat() + "," + ne.lng(),
        q: $("#q").val(),
        sw: sw.lat() + "," + sw.lng()
    };
    $.getJSON("update.php", parameters)
    .done(function(data, textStatus, jqXHR) {

        // remove old markers from map
        removeMarkers();

        // add new markers to map
        for (var i = 0; i < data.length; i++)
        {
            addMarker(data[i]);
        }
        
        // update country for macquee
        if (data.length > 0)
        {
            country = data[0].admin_name1; // for mqfire, mqUrl
            mqfire(country); // search state of country
            //console.log("#update "+country); // DEBUG
        }

     })
     .fail(function(jqXHR, textStatus, errorThrown) {

         // log error to browser's console
         console.log(errorThrown.toString());
     });
}

/** TO BE DELETE --- for debug only
 * Enumerating all properties of an object
 * returns an array containing all own properties' names (enumerable or not)
 * of an object o.
 * 
 * ref: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Working_with_Objects#Objects_and_properties
 */
function listAllProperties(o) {
    var objectToInspect;
    var result = [];
    
    for (objectToInspect = o;
    objectToInspect !== null;
    objectToInspect = Object.getPrototypeOf(objectToInspect) ) {
        result = result.concat(Object.getOwnPropertyNames(objectToInspect));
    }
    
    //return result;
    console.log(result);
}