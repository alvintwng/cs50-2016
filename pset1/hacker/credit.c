/** 
*credit.c
* Amex 15 digits - start  with 34 or 37
* Mastercard 16 digits - start with 51,52,53,54 or 55
* Visa 13 and 16 digits - start with 4
*
* 1. Multiply alternate digit by 2 from left, 
*         and these multply-ed digits, All add togather
* 2. Add (1.) to all the add digits
* 3. If last digit is 0, then card is legit
*
*   Example: AmEx : 378282246310005
*     1. multiply the number's second-to-last digit:
*        7*2 + 2*2 + 2*2 + 4*2 + 3*2 + 0*2 + 0*2
*        that gives us: 14+4+4+8+6+0+0 
*        Now add those products' digits (not the products themselves)
*        1+4  + 4 + 4 + 8 + 6 + 0 + 0 = 27
*     2. Add this sum (27) to sum of digits not multiplied   
*        27 + 3 + 8 + 8 + 2 + 6 + 1 + 0 + 5 = 60
*     3. The last digit in that sum (60) is 0. So te card is legit.
*
* Pseudocode
* Get card number, Getlonglong
* Check length 13, 15 or 16 digits 
* DO if  position is not less than zero
* Initialize for Digi position, and that position value
* Determine this digit at this position and added into the TSum
* Decrease Position and its value by 10, for next
*
* For First(Odd), add into TSum
*
* For every second(even) digit, multiply by 2,
* If value more than 10, then adds its digit togather into the TSum
*
* If position less than zero, 
* Check on the last digit of TSum
*
* If last digit is zero, check on 1st, !st 2nd digits 
* Type of cards.
*
* Print its card type
*
*
*
*
* check50 2014.fall.hacker1.credit credit.c
*
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
// Init digit position, (pndigit) and value (pnvalue)
    long long pndigit = 0;
    long long pnvalue = 0;
    long long cardn;
    int dvvalue = 0;
    int tsum = 0;
    int xdvvalue;
    string cardtype;
    int lastzero;

    
//Get card number, Getlonglong
    printf("Number: ");
    cardn = GetLongLong();
//    printf ("cardn = %lld\n", cardn);
    
// Card: Amex 15digits, start with 34   
    if (cardn > 340000000000000 && cardn < 350000000000000)
    {
            pndigit = 100000000000000;
            cardtype = "AMEX";
    }
    
// Card: Amex 15digits, start with 37   
    else if (cardn > 370000000000000 && cardn < 380000000000000)
    {
            pndigit = 100000000000000;
            cardtype = "AMEX";
    }
    
// Card: Mastercard 16digits, start with 51 to 55   
    else if (cardn > 5100000000000000 && cardn < 5600000000000000)
    {
            pndigit = 1000000000000000;
            cardtype = "MASTERCARD";
    }
    

// Card: Visa 13digits, start with 4   
    else if (cardn > 4000000000000 && cardn < 5000000000000)
    {
            pndigit = 1000000000000;
            cardtype = "VISA";
    }

// Card: Visa 16digits, start with 4   
    else if (cardn > 4000000000000000 && cardn < 5000000000000000)
    {
            pndigit = 1000000000000000;
            cardtype = "VISA";
    }    

/* let say the card numner is  6 digits long, round down
*    else if (cardn > 100000 && cardn < 199999)
*    {
*        pndigit = 100000;
*        pnvalue = cardn;
*        cardtype = "6digits card"; 
*    }
*
* //let say the card numner is  5 digits long, round down
*    else if (cardn > 10000 && cardn < 19999)
*    {
*        pndigit = 10000;
*        pnvalue = cardn;
*        cardtype = "5digits card"; 
*    }
*/
    
    else
    {
        pndigit = -1;
        cardtype = "INVALID";
    }


// print all digits in odd and even
//    printf ("pndigit = %lld ; pnvalue = %lld \n", pndigit, pnvalue); 
//    printf ("****\n");
    do
    {
        // ODD DIGIT
            dvvalue = (pnvalue / pndigit);
            tsum = tsum + dvvalue;
//            printf ("dvvalue = %i; tsum = %i ; ", dvvalue, tsum); 
//            printf ("pndigit = %lld ; pnvalue = %lld\n", pndigit, pnvalue); 
            // next digit
            pnvalue = (pnvalue - (dvvalue * pndigit));
            pndigit = pndigit /10;

        
        // EVEN digit, dvvalue is double
        if (pndigit > 0)
        {
            dvvalue = pnvalue / pndigit;
            if ( dvvalue >= 5 )
            {
                xdvvalue = dvvalue + dvvalue;
                tsum = tsum +  (xdvvalue / 10) + (xdvvalue -10);
//                printf ("dvvalue = %i; tsum = %i ; ", dvvalue, tsum); 
//                printf ("pndigit = %lld ; pnvalue = %lld\n", pndigit, pnvalue); 
                // next digit
                pnvalue = (pnvalue - (dvvalue * pndigit));
                pndigit = pndigit /10;
            }
                       
            
            else
            {
            tsum = tsum + dvvalue + dvvalue;
//            printf ("dvvalue = %i; tsum = %i ; ", dvvalue, tsum); 
//            printf ("pndigit = %lld ; pnvalue = %lld\n", pndigit, pnvalue); 
            // next digit
            pnvalue = (pnvalue - (dvvalue * pndigit));
            pndigit = pndigit /10;
            }
         
        }
    } 
    while (pndigit > 0);


// tSum last digit is zero?

    lastzero = (tsum - (tsum / 10));

    if (lastzero == 0)
    {
        printf("%s\n", cardtype);
    }    
    else
    {
        printf("INVALID\n");
    }
    
}
/*OUTPUT
~/workspace/pset1/hacker $ ./credit
Number: 378282246310005
AMEX
~/workspace/pset1/hacker $ ./credit
Number: 
4012888888881881Retry: 
VISA
~/workspace/pset1/hacker $ check50 2015.fall.hacker1.credit credit.c
:) credit.c exists
:) credit.c compiles
:) identifies 378282246310005 as AMEX
:) identifies 371449635398431 as AMEX
:) identifies 5555555555554444 as MASTERCARD
:) identifies 5105105105105100 as MASTERCARD
:) identifies 4111111111111111 as VISA
:) identifies 4012888888881881 as VISA
:) identifies 1234567890 as INVALID
:) rejects a non-numeric input of "foo"
:) rejects a non-numeric input of ""
https://sandbox.cs50.net/checks/1878a6c7e38d4441b8c9404944169bba
~/workspace/pset1/hacker $ 
*/