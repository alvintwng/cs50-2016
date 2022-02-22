/**
 * fifteen.c
 * 2022 Feb 23, revised to added in cs50.h & Makefile 
 *
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// blank tile position variable
int bi;
int bj;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
bool tileavail(int blanki, int blankj, int btile);
bool tileswap(int availi, int availj);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    //initialise blank tile position 
    bi = d-1;
    bj = d-1;
    
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{

    //board[i][j] represent the element at row i and col j
    //start in decending order. If number of tiles is odd, swap 2 and 1.
    
    int numbered = d*d -1;

    for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                board[i][j] = numbered;
                numbered--;
            }
        }

    //if number of tiles is odd than swap 2 and 1
    // swap if not divisible by 2, i.e. remainder is 1 
    if ( (d*d-1)%2 == 1)
    {
        int tmp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = tmp;
    }
}


/**
 * Prints the board in its current state.
 */
void draw(void)
{
    //Print the current state of the board
    //Print a blank space before single-digit

    printf("\n");
    
    for (int i = 0; i < d; i++)
        {
            printf(" ");
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] == 0)
                {
                    printf("  _");
                }
                else
                printf(" %2d",board[i][j]);
            }
            printf("\n");
            printf("\n");
        }
}


/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 * 
 * Edit the board array... only if the move is legal
 * check Left, Right, Top, Bottom of blank tile if available to move
 * 
 * using funtion tilevail() and tileswap() to check and swap blank tile
 */
bool move(int tile)
{
    //to check top of blank tile
    if (tileavail(bi-1, bj, tile))
        {
            tileswap(bi-1,bj);
            return true;
        }
        
    //to check below of blank tile
    if (tileavail(bi+1, bj, tile))
        {
            tileswap(bi+1, bj);
            return true;
        }

    //to check left of blank tile
    if (tileavail(bi, bj-1, tile))
        {
            tileswap(bi,bj-1);
            return true;
        }        

    //to check right of blank tile
    if (tileavail(bi, bj+1, tile))
        {
            tileswap(bi,bj+1);
            return true;
        }

    //illegal move
    return false;
}


/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 * 
 * comparing with running number from first tile 
 */
bool won(void)
{
    // start with first tile of number 1
    int rightt = 1;
    
    for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] != rightt)
                    return false;    
                else
                {
                // next number
                rightt++;
                
                // return true if last tile in place
                if (board[i][j] == d*d-1)
                    return true;
                }
            }
        }
    return true;
}



/**
 * Return true if available tiles allow to move,
 * and check with input tile
 */
bool tileavail(int blanki, int blankj, int btile)
{
    //check is within the board dimension
    if ((0 < blanki < d) || (0 < blankj < d)  )
    {
        // check if input tiles number match with available tile
        if (btile == board[blanki][blankj])
            return true;    
    }
    return false;
}


/**
 * swap the blank tile, board[bi][bj] with selected tile
 * reset the position of blank tile.
 */
bool tileswap(int availi, int availj)
{
    //swap tile with local blank tile 
    int tmp = board[bi][bj];
    board[bi][bj] = board[availi][availj];
    board[availi][availj] = tmp;
    
    //new location of blank tile
    bi = availi;
    bj = availj;
    
    return true;
}

/*OUTPUT
antw@Mac-mini fifteen % vi Makefile
antw@Mac-mini fifteen % vi fifteen.c
antw@Mac-mini fifteen % make
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror   -c -o fifteen.o fifteen.c
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror   -c -o cs50.o cs50.c
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -o fifteen fifteen.o cs50.o 
antw@Mac-mini fifteen % ./fifteen
Usage: fifteen d
antw@Mac-mini fifteen % ./fifteen 4

WELCOME TO GAME OF FIFTEEN

  15 14 13 12

  11 10  9  8

   7  6  5  4

   3  1  2  _

Tile to move: 
Tile to move: 0
antw@Mac-mini fifteen % make clean
*/
