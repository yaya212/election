/*    Note:
you should search for the difference between ++h and h++ in the looping and functions.
 */
//This program draws the pyramid of mario
#include <cs50.h>
#include <stdio.h>
//function responsible for drawing the pyramid
void draw(int x);
int main(void)
{
    int h;//h holds the height of pyramid from the user
    //this loop validates the user input to be between 1 and 8 inclusive
    do
    {
        h = get_int("Enter the height of the pyramid:\n");
    }
    while (h > 8 || h < 1);
    draw(h);
}
//function responsible for printing spaces performed using a recursion
// s holds the height of pyramid
// c holds the current level of pyramid
// sc is the spaces counter
void spaces(int s, int c, int sc)
{
    //base condition
    if (sc == (s - c))
    {
        return;   
    }
    else
    {
        printf(" ");
        spaces(s, c, ++sc);
    }
}
//function responsible for printing hashes using recursion
//c holds the current level of pyramid
//hc is the hashes counter
void hashes(int c, int hc)
{
    //base condition
    if (hc == c)
    {
        return;
    }
    else
    {
        printf("#");
        hashes(c, ++hc);
    }
}
// x holds the height of pyramid
void draw(int x)
{
    int count = 0;//count is a counter that is passed to the spaces function and the hashes function as well
    for (int i = 1; i <= x; i++)
    {
        spaces(x, i, count);   
        hashes(i, count);
        printf("  ");
        hashes(i, count);
        printf("\n");
        
    }
}
