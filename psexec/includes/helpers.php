<?php

/** added by NGTW
*/
require_once("config.php");


    /**
     * Logs out current user, if any.  Based on Example #1 at
     * http://us.php.net/manual/en/function.session-destroy.php.
     */
    function logout()
    {
        // unset any session variables
        $_SESSION = [];

        // expire cookie
        if (!empty($_COOKIE[session_name()]))
        {
            setcookie(session_name(), "", time() - 42000);
        }

        // destroy session
        session_destroy();
    }


/**
 * Looks up news articles for specified geography. Retuns an array of
 * associative arrays, each of which has two keys: link and title.
 */
function lookup($geo)
{
    // enable $_SESSION
    @session_start();

    // if this geo was cached
    if (isset($_SESSION["cache"], $_SESSION["cache"][$geo]))
    {
        // within the past hour
        if (time() < $_SESSION["cache"][$geo]["timestamp"] + 60 * 60)
        {
            // return cached articles
            return $_SESSION["cache"][$geo]["articles"];
        }
    }

    // (soon-to-be numerically indexed) array of articles
    $articles = [];
    
    // headers for proxy servers
    $headers = [
        "Accept" => "*/*",
        "Connection" => "Keep-Alive",
        "User-Agent" => sprintf("curl/%s", curl_version()["version"])
    ];
    $context = stream_context_create([
        "http" => [
            "header" => implode(array_map(function($value, $key) { return sprintf("%s: %s\r\n", $key, $value); }, $headers, array_keys($headers))),
            "method" => "GET"
        ]
    ]);

    // download RSS from Google News if possible
    $contents = @file_get_contents("http://news.google.com/news?geo=" . urlencode($geo) . "&output=rss", false, $context);
    if ($contents !== false)
    {
        // parse RSS
        $rss = @simplexml_load_string($contents);
        if ($rss !== false)
        {
            // iterate over items in channel
            foreach ($rss->channel->item as $item)
            {
                // add article to array
                $articles[] = [
                    "link" => (string) $item->link,
                    "title" => (string) $item->title
                ];
            }

            // cache articles
            if (!isset($_SESSION["cache"]))
            {
                $_SESSION["cache"] = [];
            }
            $_SESSION["cache"][$_GET["geo"]] = [
                "articles" => $articles,
                "timestamp" => time()
            ];
        }
    }

    // else from the Onion
    else
    {
        $contents = @file_get_contents("http://www.theonion.com/feeds/rss", false, $context);
        if ($contents !== false)
        {
            // parse RSS
            $rss = @simplexml_load_string($contents);
            if ($rss !== false)
            {
                // iterate over items in channel
                foreach ($rss->channel->item as $item)
                {
                    // add article to array
                    $articles[] = [
                        "link" => (string) $item->link,
                        "title" => (string) $item->title
                    ];
                }
            }
        }
    }

    return $articles;
}


/** added by NgTW
 * Apologizes to user with message.
 */
function apologize($message)
{
    render("upper_agt.php", "apology.php",["message" => $message]);
}

/** added by NgTW
 * Facilitates debugging by dumping contents of argument(s)
 * to browser.
 */
function dump()
{
    $arguments = func_get_args();
    require("../views/dump.php");
    exit;
}

    /**
     * Redirects user to location, which can be a URL or
     * a relative path on the local host.
     *
     * http://stackoverflow.com/a/25643550/5156190
     *
     * Because this function outputs an HTTP header, it
     * must be called before caller outputs any HTML.
     */
    function redirect($location)
    {
        if (headers_sent($file, $line))
        {
            trigger_error("HTTP headers already sent at {$file}:{$line}", E_USER_ERROR);
        }
        header("Location: {$location}");
        exit;
    }

/** added by NgTW
 * Renders view, passing in values.
 */
function render($upview, $view, $values = [])
{
    // if view exists, render it
    if (file_exists("../views/{$upview}"))
    {
        // extract variables into local scope
        extract($values);

        // render view (between header and footer, ADD upper.php)
        require("../views/header.php");
        require("../views/{$upview}");
        require("../views/{$view}");
        require("../views/footer.php");
        exit;
    }

    // else err
    else
    {
        trigger_error("Invalid view: {$upview}", E_USER_ERROR);
    }
}

?>