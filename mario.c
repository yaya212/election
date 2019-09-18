//draws the pyramid of mario
#include <cs50.h>
#include <stdio.h>
void draw(int h);
void spaces(int m);
void hashes(int i);
int main(void)
{
    int h;// h represents the height of the pyramid
    //This loop checks that the user enters a positive integer
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    draw(h);
}
//Function responsible for drawing the whole pyramid
void draw(int h)
{
    for (int i = 1; i <= h; i++)
    {
        spaces(h - i);
        hashes(i);
        printf("  ");
        hashes(i);
        printf("\n");
    }
}
//Function responsible for printing the spaces
void spaces(int m)
{
    int k = 0;// k is a counter to count the number of spaces before printing out the hashes
    //Note the number of space in the first rows is the height - 1 and each coming row the number of spaces decrease by one
    //checks if the counter reaches the required amount per row
    while (k < m)
    {
        printf(" ");
        k++;
    }

}
//Function responsible for printing the hashes
void hashes(int i)
{
    //The loop responsible for the printing out of hashes
    for (int j = 0; j < i; j++)
    {
        printf("#");
    }
}