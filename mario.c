//draws the pyramid of mario
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;// h represents the height of the pyramid
    //This loop checks that the user enters a positive integer
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    int k;// k is a counter to count the number of spaces before printing out the hashes
    //Note the number of space in the first rows is the height - 1 and each coming row the number of spaces decrease by one
    for (int i = 1; i <= h; i++)
    {
        k = 0;
        //checks if the counter reaches the required amount per row
        while (k < h - i)
        {
            printf(" ");
            k++;
        }
        //The loop responsible for the printing out of hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
