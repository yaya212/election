#include<stdio.h>
#include<cs50.h>
#include<math.h>
void validate(long c);
int main(void)
{
    //string s;
    long cn;
    cn = get_long("Enter the credit card number:\n");
    /*= (string)cn;
    printf("the credit card number is %s\n",s);*/
    validate(cn);
}
int p = 0;
int s = 0;
int ftd = 0;
void algo(long c)
{
    if(c < 100 && c > 9 )
    {
        ftd = c;
    }
    if(p % 2 != 0)
    {
        int temp = c % 10;
        printf("temp is %d\n",temp);
        if ((temp * 2) > 9)
        {
            temp *= 2;
            printf("new temp is %d\n",temp);
            s += (temp % 10) + (temp/10);
            printf("sum1 is %d\n",s);
        }
        else
        {
            s += temp * 2;
            printf("sum2 is %d\n",s);
        }
        p++;
        if(c < 10)
        {
            return;
        }        
        algo(c/10);
    }
    else if(p % 2 == 0)
    {
        s += (c % 10);
        printf("sum = %d\n", s);
        p++;
        if(c < 10)
        {
            return;
        }        
        algo(c/10);
    }
        
}
void validate(long x)
{
    algo(x);
    printf("length is %d\n",p);
    printf("ftd is %d\n",ftd);
    if(s % 10 == 0)
    {
        switch (p)
        {
            case 13: 
                if((ftd/10) == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 15: 
                if(ftd == 34 || ftd == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 16:
                if((ftd/10) == 4)
                {
                    printf("VISA\n");
                }
                else if(ftd >= 51 && ftd <= 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default: 
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
