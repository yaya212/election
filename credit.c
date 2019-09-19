//Checks the validity of credit cards.
#include<stdio.h>
#include<cs50.h>
//check function performs luhn's algorithm
void check(long Num, int *c, int *sum1, int *sum2, int *ftd);
int main(void)
{
    long Num = get_long("Number: ");//Num holds the credit card number
    int c = 0, sum1 = 0, sum2 = 0, ftd;/*ftd is the first 2 digits , c is used as a reference for the position of the digit
    and also as a counter, sum1 is sum of the other digit after being multiplied by 2, sum1 is the sum of the remaining digits*/
    check(Num, &c, &sum1, &sum2, &ftd);
    int fd = (ftd / 10) % 10;//fd holds the first digit
    //printf("first digit = %i\n", fd);
    if ((sum1 + sum2) % 10 == 0)//checks if the totals of both sums give a number that is divisible by 10
    {
        /*checks first the length of the credit cards if it matches any of the lengths of the popular credit cards(VISA,AMEX,MASTERCARD)
        then checks if it's first 2 digits or 1 digit match the pattern of these popular credit cards*/
        switch (c)
        {
            case 13:
                if (fd == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 16:
                if (ftd >= 51 && ftd <= 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (fd == 4)
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
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
void check(long Num, int *c, int *sum1, int *sum2, int *ftd)
{
    int curr;//curr holds every last digit in the credit card number after getting its remainder from 10
//This loop ends when the credit card gives a 0 after being divided by 10
    while (Num > 0)
    {
        curr = Num % 10;//this equation gives you the last digit
        Num /= 10;//The next step is to remove this number from the original credit card number
//This condition is performed to get the first 2 digits in the credit card
        if (Num < 100 && Num > 9)
        {
            *ftd = Num;
        }
        //checks if the position of the digit is odd or even
        //we consider the last digit having a position 0
        //with this we can categorize it whether it will be considered within the sum1 or sum2
        if (*c % 2 == 0)
        {
            *sum2 += curr;
        }
        else
        {
            curr *= 2;
//here we check if after the multiplication by 2 the product is 2 digits or not if so we extract each digit and add it to sum2
            if (curr > 9)
            {
                *sum1 += (curr % 10);
                curr /= 10;
                *sum1 += (curr % 10);
            }
            else
            {
                *sum1 += curr;
            }
        }
        (*c)++;
    }
}