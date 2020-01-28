#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdlib.h>
int check(string x, int y);
void cipher(string p, char c[], int d, int l);
int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string k = argv[argc - 1];
        int l = strlen(k);
        int f = check(k,l);
        if(f == 1)
        {
            int d = atoi(k);
            string p = get_string("plaintext: ");
            l = strlen(p);
            char c[l + 1];
            printf("ciphertext: ");
            cipher(p , c, d, l);
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }

    }
}
int i = 0;
int check(string x, int y)
{
    if(x[0] == '-')
    {
        return 0;
    }
    if(i == y)
    {
        return 1;
    }
    else
    {
        if(!isdigit(x[i]))
        {
            return 0;
        }
        else
        {
            i++;
            return check(x, y);
        }
    }
}
int j = 0;
void cipher(string p, char c[], int d, int l)
{
    if(j == l)
    {
        c[j] = '\0';
        printf("%s\n", c);
        return;
    }
    else
    {
        if(isalpha(p[j]))
        {
            if(p[j] >= 'A' && p[j] <= 'Z')
            {
                c[j] = 'A' + ((p[j] - 'A' + d) % 26);
            }
            else if(p[j] >= 'a' && p[j] <= 'z')
            {
                c[j] = 'a' + ((p[j] - 'a' + d) % 26);
            }
        }
        else
        {
            c[j] = p[j];
            printf("%c", c[j]);
        }
        j++;
        cipher(p, c, d, l);
    }
}