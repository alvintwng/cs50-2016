//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    updateScoreboard(window, label, points);

    // initial ball velocity
    double Stdvelocity = 3.0 ;      
    double Xvelocity = Stdvelocity;  
    double Yvelocity = Stdvelocity;
    
    // wait for click before start
    waitForClick();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // move Ball along  x-axis
        move(ball, Xvelocity, Yvelocity);
            
        // Detect collision object
        GObject object = detectCollision(window, ball);
        
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure Paddle follows 
                double x = getX(event) - getWidth(paddle) / 2;
                setLocation(paddle, x, 540);
            }
        }        
           
        if (object != NULL) // need this NULL, otherwise strcmp hang
        {
            if (getY(ball) < 200)
            {
                if (strcmp (getType(object), "GRect") == 0)
                {
                    //removeGWindow
                    removeGWindow(window, object);
                    bricks --;
                    points ++;
                    //updateScoreboard(window, label, bricks);
                    updateScoreboard(window, label, points);
                }
            }
                
			// bounce off paddle, and change speed 
            if (strcmp (getType(object), "GRect") == 0)
            {
                Yvelocity = -Yvelocity;
                Xvelocity = Stdvelocity/2 - (Stdvelocity*drand48());
            }
        }

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            Xvelocity = -Xvelocity;
        }

        // bounce off left edge of window
        if (getX(ball) <= 0)
        {
            Xvelocity = -Xvelocity;
        }

        // bounce off top edge of window
        if (getY(ball) <= 0)
        {
            Yvelocity = -Yvelocity;
        }

        // clear if at bottom edge of window
        if (getY(ball) >= 600-RADIUS)
        {
            lives = lives -1;
            waitForClick();
            setLocation(ball, getWidth(window)/2, getHeight(window)/2);
        }
                    
        // linger before moving again
        pause(10);
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**

from CS50

GWindow newGWindow(double width, double height);
 Creats and displays a graphocs window with the specified dimensions,
 Usage:
 gw = newGWindow(width, height)


void removeGWindow(GWindow gw, GObject gobj);
//(void remove(GWindow gw, GObject gobj);
Removes the object from its container or region,
Usage
   remove(gw, gobj);

*/

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    for (int y=0; y<=ROWS-1; y++)
    {
        for (int x=0; x<=COLS; x++)
        {
            GRect bricks = newGRect(x*40+2, y*15+50, 35, 10);
            switch (y)
            {
                case 0: setColor(bricks, "CYAN"); break;
                case 1: setColor(bricks, "GREEN"); break;
                case 2: setColor(bricks, "YELLOW"); break;
                case 3: setColor(bricks, "ORANGE"); break;
                case 4: setColor(bricks, "RED"); break;                                                          
            }
            setFilled(bricks, true);
            add(window, bricks);
        }
        // pause(250); // for TESTING
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval((getWidth(window)/2)-RADIUS, getHeight(window)/2, RADIUS*2, RADIUS*2);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);    
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(170, 540, 60, 10);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-72");
    setColor(label, "GRAY"); //i set the color
    add(window, label);

    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
/*OUTPUT 
~/workspace/pset3/breakout $ make
clang -ggdb3 -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o breakout breakout.c -lcs -lm
breakout.c:17:10: fatal error: 'spl/gevents.h' file not found
#include <spl/gevents.h>
         ^
1 error generated.
make: *** [breakout] Error 1
~/workspace/pset3/breakout $ 

it don't work in CS50 IDE, but work in CS50 Appliance 
*/