//cs50 pset7 notes
//Cs50 pset7 video
//pset7 log


/* cs50 pset7 notes

Pset7 Recommended Reading
http://diveintohtml5.info/

http://php.net/manual/en/langref.php


to format int
//http://php.net/manual/en/function.number-format.php

Bootstrap for CSS
<!-- http://getbootstrap.com/ —>

you can employ SQL "transactions" (with InnoDB tables). See http://dev.mysql.com/doc/refman/5.5/en/sql-syntax-transactions.html if curious.

use of a regular expression.
http://www.php.net/preg_match

*/

/*Cs50 pset7 video

Permissions
Folders: chmod 711 folder
Images, HTML, CSS, just: chmod 644 file
 users shouldn't execute an image!
Php: chmod 600 file
 users shouldn't see your Php code
Chmod 644 img/* js//*
*/

/* pset7 log
/home/ubuntu/workspace/ $ update50

/home/ubuntu/workspace/ $ sudo apt-get install -y php5-xdebug

/home/ubuntu/workspace/ $ wget http://cdn.cs50.net/2015/fall/psets/7/pset7/pset7.zip

/home/ubuntu/workspace/ $ wget http://cdn.cs50.net/2015/fall/psets/7/pset7/pset7.sql

/home/ubuntu/workspace/ $ unzip pset7.zip

/home/ubuntu/workspace/ $ cd pset7
/home/ubuntu/workspace/pset7/ $ ls
config.json  includes/  public/  vendor/  views/

/home/ubuntu/workspace/pset7/ $ chmod a+x ~/workspace/pset7/public

/home/ubuntu/workspace/pset7/ $ cd public
/home/ubuntu/workspace/pset7/public/ $ ls
css/  fonts/  img/  index.php  js/  login.php  logout.php
/home/ubuntu/workspace/pset7/public/ $ chmod a+x css fonts img js

/home/ubuntu/workspace/pset7/public/ $ chmod a+r css/* fonts/* img/* js/*
/home/ubuntu/workspace/pset7/public/ $ killall -9 server
server: no process found
/home/ubuntu/workspace/pset7/public/ $ apache50 stop
Apache is not running!
/home/ubuntu/workspace/pset7/public/ $ apache50 start ~/workspace/pset7/public
Setting Apache's document root to /home/ubuntu/workspace/pset7/public ...
 * Starting web server apache2
 * 
Apache started successfully!
Your site is now available at https://ide50-twng.cs50.io

Your site is now available at https://ide50-twng.c9users.io

Your site is now available at https://ide50-twng.cs50.io

/home/ubuntu/workspace/pset7/public/ $ mysql50 start
MySQL is already running!
/home/ubuntu/workspace/pset7/public/ $ 
/home/ubuntu/workspace/ $ username50
twng
/home/ubuntu/workspace/ $ password50
v1kCjsvLYytrBTGV
/home/ubuntu/workspace/ $ 

https://ide50-twng.cs50.io/

/home/ubuntu/workspace/ $ chmod 775 ~/workspace/pset7
/home/ubuntu/workspace/ $ apache50 start `
 * Stopping web server apache2                                                                                                * 
Setting Apache's document root to /home/ubuntu/workspace/pset7/public ...
 * Starting web server apache2                                                                                                * 
Apache started successfully!
Your site is now available at https://ide50-twng.cs50.io
/home/ubuntu/workspace/ $ echo now can see the websites!
now can see the websites!

chmod 711 folder
chmod 644 images, html, css
chmod 600 php files

now in work!

https://ide50-twng.cs50.io/phpmyadmin

killall -9 server
apache50 stop
mysql50 stop
apache50 start ~/workspace/pset7/public
mysql50 start
https://ide50-twng.cs50.io/phpmyadmin

i think is chmod 775 /include *.php is ok 
*/

/* WAS
/home/ubuntu/workspace/pset7/public/ $ ls -l
total 28
drwx--x--x 2 ubuntu ubuntu 4096 Oct 26  2015 css/
drwx--x--x 2 ubuntu ubuntu 4096 Oct 26  2015 fonts/
drwx--x--x 2 ubuntu ubuntu 4096 Oct 26  2015 img/
-rw------- 1 ubuntu ubuntu  152 Oct 26  2015 index.php
drwx--x--x 2 ubuntu ubuntu 4096 Oct 26  2015 js/
-rw------- 1 ubuntu ubuntu 1450 Oct 30  2015 login.php
-rw------- 1 ubuntu ubuntu  164 Oct 26  2015 logout.php

0 - 000
1 - 001
2 - 010
3 - 011
4 - 100 r--
5 - 1-1 r-x
6 - 110 rw-
7 - 111 rwx
eg. 334 is -rw-rw-r--
775 is drwxrwxr-x

#Permission	rwx
file owner, the group, and other users

wiki: The chmod numerical format accepts up to four octal digits. 
The three rightmost digits refer to permissions for the file owner, 
the group, and other users. The optional leading digit (when 4 digits 
are given) specifies the special setuid, setgid, and sticky flags.

Numeric example[edit]
In order to permit all users who are members of the programmers group to update a file
$ ls -l sharedFile
-rw-r--r--  1 jsmith programmers 57 Jul  3 10:13  sharedFile
$ chmod 664 sharedFile
$ ls -l sharedFile
-rw-rw-r--  1 jsmith programmers 57 Jul  3 10:13  sharedFile

*/
/*

killall -9 server
apache50 stop
mysql50 stop
apache50 start ~/workspace/pset7/public
mysql50 start
https://ide50-twng.cs50.io/phpmyadmin

i think is chmod 775 /include *.php is ok 
/home/ubuntu/workspace/pset7/vendor/library50-php-5/CS50/ $ chmod 775 *.*

Since it work, 1 set back, except /include *.php
chmod 711 folder
chmod 644 images, html, css
chmod 600 php files 600 *.php
except /views *.php

/home/ubuntu/workspace/pset7/ $ chmod 600 *.*
 Warning: file_get_contents(/home/ubuntu/workspace/pset7/includes/../config.json):
 failed to open stream: Permission denied in
 /home/ubuntu/workspace/pset7/vendor/library50-php-5/CS50/CS50.php on line 95
/home/ubuntu/workspace/pset7/ $ chmod 644 *.*
Work!
/home/ubuntu/workspace/pset7/ $ chmod 640 *.*
/home/ubuntu/workspace/pset7/ $ chmod 711 includes/
/home/ubuntu/workspace/pset7/ $ chmod 711 public/
/home/ubuntu/workspace/pset7/ $ chmod 711 vendor/
/home/ubuntu/workspace/pset7/ $ chmod 711 views
/home/ubuntu/workspace/pset7/includes/ $ chmod 640 *.*   
/home/ubuntu/workspace/pset7/vendor/library50-php-5/CS50/ $ chmod 640 *.*
/home/ubuntu/workspace/pset7/public/ $ chmod 711 css
/home/ubuntu/workspace/pset7/public/ $ chmod 711 fonts
/home/ubuntu/workspace/pset7/public/ $ chmod 711 img
/home/ubuntu/workspace/pset7/public/ $ chmod 711 js
/home/ubuntu/workspace/pset7/vendor/ $ chmod 711 library50-php-5/
/home/ubuntu/workspace/pset7/vendor/library50-php-5/ $ chmod 711 CS50/
/home/ubuntu/workspace/pset7/vendor/library50-php-5/CS50/ $ chmod 711 share/

Work!
*/
/* pset7
When ready to submit, "export" your MySQL database (i.e., save it into a text file) by executing the commands below, where username is your own username, pasting your MySQL password when prompted for a password. (Recall that you can see your MySQL password by clicking the ⓘ icon toward CS50 IDE’s top-right corner.) For security, you won’t see the password as you paste it.

cd ~/workspace/pset7
mysqldump -u username -p pset7 > pset7.sql

drwxrwxr-x 6 ubuntu ubuntu   4096 Aug 12 04:34 pset7/
~/workspace/ $ chmod 711 pset7

*/
/*
Aug 24, 2016
drwx-wx--x 6 ubuntu ubuntu    4096 Aug 12 04:34 pset7/

~/workspace/pset7/ $ ls -l
-rw-rw---- 1 ubuntu ubuntu  149 Jul 28 04:34 config.json
drwx-wx--x 2 ubuntu ubuntu 4096 Oct 31  2015 includes/
-rw--w---- 1 ubuntu ubuntu 5922 Aug 11 16:58 pset7.sql
-rw--w---- 1 ubuntu ubuntu 6478 Aug 20 16:24 pset7log.c
drwx-wx--x 6 ubuntu ubuntu 4096 Aug 11 15:21 public/
drwx-wx--x 3 ubuntu ubuntu 4096 Oct 26  2015 vendor/
drwx-wx--x 2 ubuntu ubuntu 4096 Aug 11 15:18 views/

~/workspace/pset7/public/ $ ls -l
total 60
-rw-rw-r-- 1 ubuntu ubuntu 1167 Aug 11 15:47 addcash.php
-rw-rw-r-- 1 ubuntu ubuntu 2746 Aug 11 15:50 buy.php
drwx-wx--x 2 ubuntu ubuntu 4096 Aug  7 16:22 css/
drwx-wx--x 2 ubuntu ubuntu 4096 Oct 26  2015 fonts/
-rw-rw-r-- 1 ubuntu ubuntu  956 Aug 11 15:53 history.php
-rw-rw-r-- 1 ubuntu ubuntu 1619 Aug 11 15:54 htmlmail.php
drwx-wx--x 2 ubuntu ubuntu 4096 Oct 26  2015 img/
-rw-rw-r-- 1 ubuntu ubuntu 1513 Aug 11 15:54 index.php
drwx-wx--x 2 ubuntu ubuntu 4096 Oct 26  2015 js/
-rw-rw-r-- 1 ubuntu ubuntu 1450 Aug  4 07:01 login.php
-rw-rw-r-- 1 ubuntu ubuntu  164 Oct 26  2015 logout.php
-rw-rw-r-- 1 ubuntu ubuntu 1237 Aug 11 15:55 quote.php
-rw-rw-r-- 1 ubuntu ubuntu 1721 Aug 11 16:00 register.php
-rw-rw-r-- 1 ubuntu ubuntu 2438 Aug 11 16:06 sell.php
-rw-rw-r-- 1 ubuntu ubuntu 1214 Aug 11 16:08 setpassword.php


*/