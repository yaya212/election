//calculates the amount of money required to pay the change owed to the customer
#include<stdio.h>
#include<cs50.h>
//math library used to give accessibility to round function.
#include<math.h>
//counter function used to subtract from the change quarters, dimes, nickels or pennies.
int counter(int r);
int main(void)
{
    float owed;//owed holds the amount owed to the customer
//This loop ensures the user doesn't enter a negative number
    do
    {
        owed = get_float("Change owed: ");
    }
    while (owed < 0);
    int o = round(owed * 100), count = 0, r = o;//o is the amount owed to the customer in cents after rounding
//count is used to the number of coins paid that add up to form the amount owed to the customer
//r is the reaminder after subtracting from amount owed quarters, dimes, nickles or pennies.
    while (r != 0)
    {
        r = counter(r);
        count++;
    }
    printf("%i\n", count);
}
int counter(int r)
{
    if (r >= 25)
    {
        r -= 25;
        return r;
    }
    else if (r >= 10)
    {
        r -= 10;
        return r;
    }
    else if (r >= 5)
    {
        r -= 5;
        return r;
    }
    else if (r >= 1)
    {
        r -= 1;
        return r;
    }
    return r;
}