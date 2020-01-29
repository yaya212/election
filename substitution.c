#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int check(string k, int l);
void cipher(string p, char c[], int l, string k);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string k = argv[argc - 1];
        int l = strlen(k);
        if (l == 26)
        {
            int f = check(k,l);
            if(f == 1)
            {
                string p = get_string("plaintext: ");
                l = strlen(p);
                char c[l + 1];
                printf("ciphertext: ");
                cipher(p, c, l, k);
            }
            else
            {
                printf("Key must contain 26 unique alphabetical characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
}
int i = 0;
int j = 1;
int check(string k, int l)
{
    if(i == l)
    {
        return 1;
    }
    if(j == l)
    {
        return 1;
    }
    else
    {
        if (!isalpha(k[i]))
        {
            return 0;
        }
        else
        {
            if((tolower(k[i]) != k[j]) && (toupper(k[i]) != k[j]))
            {
                j++;
                return check(k, l);
            }
            else
            {
                return 0;
            }
            i++;
            j = 0;
            return check(k, l);
        }
    }
}
int h = 0, m = 0;
void cipher(string p, char c[], int l, string k)
{
    if(m == l)
    {
        c[m] = '\0';
        printf("%s\n", c);
        return;
    }

    else
    {
        if(isalpha(p[m]))
        {
            if(h == (tolower(p[m]) - 'a'))
            {
                if(islower(p[m]))
                    c[m] = tolower(k[h]);
                else
                    c[m] = toupper(k[h]);
                m++;
                h = 0;
                cipher(p, c, l, k);
            }
            else
            {
                h++;
                cipher(p, c, l, k);
            }
        }
        else
        {
            c[m] = p[m];
            m++;
            h = 0;
            cipher(p, c, l, k);
        }
    }
}