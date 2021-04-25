<?php

    /**
     * session_agt.php
     *
     * Computer Science 50
     * Final Project, NgTW
     *
     * ID session.
     */


    // enable sessions
    session_start();

    // require authentication for all pages except /login.php, /logout.php, and /register.php
    if (!in_array($_SERVER["PHP_SELF"], ["/login.php", "/logout.php"]))
    {
        if (empty($_SESSION["id"]))
        {
            redirect("login.php");
        }
    }

?>