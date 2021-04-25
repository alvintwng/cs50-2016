<?php

    require(__DIR__ . "/../includes/config.php");

    // ensure proper usage
    if (empty($_GET["geo"]))
    {
        http_response_code(400);
        exit;
    }

    // get geography's articles
    $articles = lookup($_GET["geo"]);

    // output articles as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($articles, JSON_PRETTY_PRINT));


/*
eg. https://ide50-twng.cs50.io/search.php?geo=02138

https://ide50-twng.cs50.io/articles.php?geo=Cambridge,+Iowa

https://ide50-twng.cs50.io/articles.php?geo=Cambridge,+Massachusetts

[
    {
        "link": "http:\/\/news.google.com\/news\/url?sa=t&fd=R&ct2=us&usg=AFQjCNGkuws3JJnia8T....move",
        "title": "Heat Map Shows Which Streets Will See Most Disruption with Fall Move-In - Patch.com"
    },
    
    {
        "link": "http:\/\/news.google.com\/news\/url?sa=t&fd=R&ct2=us&usg=AFQjCNEF ....  \/story.html",
        "title": "When the cook calls in sick, there's no need to panic - The Boston Globe"
    }
]



https://news.google.com/news?geo=02138&output=rss
RSS feed contains a root element called rss, the child of which is an element called channel. 
Inside of channelare elements called title, description, and link, followed by one or more 
elements called item, each of which represents an article 
*/

?>