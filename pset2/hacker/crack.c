/** crack.c
 * sudo apt-get install -y wamerican
* clang -o crack crack.c -lcrypt
* ./crack 50yoN9fp966dU
* crimson
*
*/


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>


int main(void)
{
    char salt[] = "00";
    char *password;
    char *guess;
    
    string pwd1 = GetString();
    password = crypt(pwd1, salt);
    printf("password 1/2 = %s\n", password);
    
    string pwd2 = GetString();
    guess = crypt(pwd2, salt);
    printf("password 2/2 = %s\n", pwd2);
    printf("guess = %s\n", guess);
     
    puts(strcmp(guess, password) == 0
        ? "Access Granted." : "Access Denied.");
    return 0;
 }
 /*OUTPUT
 ~/workspace/pset2/hacker $ sudo apt-get install -y wamerican
 ...

~/workspace/pset2/hacker $ clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow    crack.c  -lcrypt -lcs50 -lm -o crack
~/workspace/pset2/hacker $ ./crack
caesar
password = 00KyYgSQvqVUM
00KyYgSQvqVUM
password = 00KyYgSQvqVUM
guess = 00XuQIoYd3pO.
Access Granted.

???? since that not working !!
*/