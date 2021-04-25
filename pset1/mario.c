/** CS50 pset1
 * mario.c
 * 2016 may 10, NGTW
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(void)
 {
 //Prompt and validate user input
     //Using do-while Loop
     int height;
     do
     {
        printf("height: ");
        height = GetInt();
     }
     // loop back if height less than 1 OR more than 23
     while (height<0 || height>23 );
     
     
 //Draw the half-pyramid
     //using For-Loop
     for (int loop=0; loop<height; loop++)
        {
            //print spaces
            for (int spac=0; spac<(height-loop-1); spac++)
                {
                    printf(" ");
                }
            
            //print hashes loop
            for (int hash=0; hash<(loop+2); hash++)
                {
                    printf("#");
                }
            
            //print new line
            printf("\n");
        }
 }
 /*OUTPUT
 ~/workspace/pset1 $ ./mario
height: 8
       ##
      ###
     ####
    #####
   ######
  #######
 ########
#########
~/workspace/pset1 $ 
 */