//this program checks if a credit card is valid according to Luhn's algorithm
#include<stdio.h>
#include<cs50.h>
#include<math.h>
//function responsible for validation
void validate(long c);
int main(void)
{
    long cn;//cn holds the credit card number 
    cn = get_long("Enter the credit card number:\n");
    validate(cn);
}
int p = 0;//p holds the current position of digit in the credit card
int s = 0;//s holds the total sum
int ftd = 0;//ftd holds the first two digits in the credit card number
void algo(long c)
{
    //this condition is used to extract the first two digits in the credit card number
    if (c < 100 && c > 9)
    {
        ftd = c;
    }
    //checking if the it is the other digit starting from the end 
    if (p % 2 != 0)
    {
        int temp = c % 10;//temp hold the this other digit in order to process it 
        //checking if this other digit after multiplying by 2 gives a 2 digit number is so we break this number into its 2 digits and           add them up else we just add this other digit after multiplying by 2
        if ((temp * 2) > 9)
        {
            temp *= 2;
            s += (temp % 10) + (temp / 10);
        }
        else
        {
            s += temp * 2;
        }
        p++;
        //base condition
        if (c < 10)
        {
            return;
        }        
        algo(c / 10);
    }
    else if (p % 2 == 0)
    {
        s += (c % 10);
        p++;
        //base condition
        if (c < 10)
        {
            return;
        }        
        algo(c / 10);
    }
        
}
void validate(long x)
{
    algo(x);//function responsible for doing the summation and getting the total according to Luhn's algorithm
    //afte getting the total we check according to the validation of each type of credit card 
    if (s % 10 == 0)
    {
        switch (p)
        {
            case 13: 
                if ((ftd / 10) == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 15: 
                if (ftd == 34 || ftd == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 16:
                if ((ftd / 10) == 4)
                {
                    printf("VISA\n");
                }
                else if (ftd >= 51 && ftd <= 55)
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
