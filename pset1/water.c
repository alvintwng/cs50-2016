#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask user for input of minutes
    printf("minutes: ");
    int x = GetInt();
    
    // computer to bottles
    printf("bottles: %i\n", x*12);
}
/*OUTPUT
~/workspace/pset1 $ ./water
minutes: 10
bottles: 120
*/