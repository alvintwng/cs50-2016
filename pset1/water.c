/** water.c
* 2022 Feb 20, revised to removed cs50.h
**/

#include <stdio.h>

int main(void)
{
    // ask user for input of minutes
    int x;
    printf("minutes: ");
    scanf("%d", &x);  // was  int x = GetInt();
    
    // computer to bottles
    printf("bottles: %i\n", x*12);
}
/*OUTPUT
antw@Mac-mini c % gcc -g -Wall water.c -o water
antw@Mac-mini c % ./water
minutes: 10
bottles: 120
*/
