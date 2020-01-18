#include<stdio.h>
#include<cs50.h>
#include<math.h>
void calc_owed(int c);
int main(void)
{
    float o;
    do
    {
        o = get_float("Enter the amount owed:\n");
    }
    while(o < 0);
    int cents = round(o * 100);
    //printf("owed:%d\n",cents);
    calc_owed(cents);
}
int count = 0;
int a[4] = {25,10,5,1};
int l = sizeof(a)/sizeof(a[0]);
int flag = 0;
void calc_owed(int c)
{
    if (c == 0)
    {
        printf("The minimum number of coins needed to pay the owed amount is %d\n",count);
        flag = 1;
        return;
    }
    else
    {
        //printf("l = %d\n",l);
        for(int i = 0; i < l; i++)
        {
           if(c >= a[i])
            {
                count++;
                c -= a[i];
                calc_owed(c);
            }
            if(flag == 1 )
                return;
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
