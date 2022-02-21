/*  greedy.c
*  2022 Feb 20, revised to removed cs50.h.
*
* quarter ($0.25)
* dime ($0.10)
* nicket ($0.05)
* penny ($0.01)
*
* TODO *
** Promt user for an amount of change
** Always use the largest coin possible
** Keep track of coin uses
** Print the final amount of coins
*
* Pseudocode *
* get amount in dollars
* while (quarters can be used)
*  increase count
*  amount decrease by a quarter
* while (dimes can be used)
*  increase count
*  amount decrease by a dime
* (etc ... )
*
* print number of coins used
*
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
//Prompt user for an amount of change
    float owed;
    do
    {
        printf("O hai! How much change is owed? \n");
        scanf("%f", &owed);   //  owed = GetFloat();
    }
    while (owed <= 0);
    
    // Round up nearest cents, using round
    owed = (owed*100);
    int cent = round(owed);
    
    // Initialised counter, and coin types
    int count = 0;
    int chgowe;
    int quarter;
    int dime;
    chgowe = cent;
    
    //count no. of quarter
    quarter = (chgowe/25);
    chgowe = (chgowe - (quarter*25));
    
    // dime, 10 cents
    dime = (chgowe/10);
    chgowe = (chgowe - (dime*10));
    
    //nickets, 5 cents
    int nick;
    nick = (chgowe/5);
    chgowe = (chgowe - (nick*5));
    
    //penny, 1 cent
    int penn;
    penn = (chgowe/1);
    chgowe = (chgowe - (penn*1));
    
    //Total coins
    count = (quarter + dime + nick + penn);
    printf ("%d\n", count);
    
}
/*  OUTPUT
~/workspace/pset1 $ 
antw@Mac-mini c % gcc -g -Wall greedy.c -o greedy
antw@Mac-mini c % ./greedy
O hai! How much change is owed? 
0.41
4
*/
