//calculates the minimum number of coins required to pay the owed amount to the customer
#include<stdio.h>
#include<cs50.h>
#include<math.h>
//function responsible for calculating the least number of coins using recursion
void calc_owed(int c);
int main(void)
{
    float o;//o holds the amount owed in floating point
    //this loop validates that the amount owed is a non-negative number
    do
    {
        o = get_float("Enter the amount owed:\n");
    }
    while (o < 0);
    int cents = round(o * 100);//cents holds the amount owed in integer
    //printf("owed:%d\n",cents);
    calc_owed(cents);
}
int count = 0;//count is the variable responsible for counting the number of coins
int a[4] = {25, 10, 5, 1};//a is an array holding the available change in the cashier
int l = sizeof(a) / sizeof(a[0]);//l holds the length of this array
int flag = 0;//flag responsible for breaking the for loop inside function when the all the amount is paid
void calc_owed(int c)
{
    //base condition
    if (c == 0)
    {
        printf("The minimum number of coins needed to pay the owed amount is %d\n", count);
        flag = 1;
        return;
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            if (c >= a[i])
            {
                count++;
                c -= a[i];
                calc_owed(c);
            }
            if (flag == 1)
            {
                return;
            }
        }
    }
    /*else if(c >= 25)
    {
        count++;
        calc_owed(c-25);
    }
    else if(c >= 10)
    {
        count++;
        calc_owed(c-10); 
    }
    else if(c >= 5)
    {
        count++;
        calc_owed(c-5);        
    }
    else if(c >= 1)
    {
        count++;
        calc_owed(c-1);        
    }*/
}
