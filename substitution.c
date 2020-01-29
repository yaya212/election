//the program decodes the message by subtituting each character in the plaintext by the corresponding character in the string key
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int check(string k, int l);//used to validate the key
void cipher(string p, char c[], int l, string k);//used to decode the given plaintext
int main(int argc, string argv[])
{
    //checks that there are 2 arguments in the terminal window including the ./program name
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //executes when there are exactly 2 arguments including the ./program name
    else
    {
        string k = argv[argc - 1];//holds the string key
        int l = strlen(k);//holds the length of string key
        //executes if the key has 26 characters
        if (l == 26)
        {
            int f = check(k, l);//f holds the return value of validation
            //executes if the key is validated and correct
            if (f == 1)
            {
                string p = get_string("plaintext: ");//p holds the plaintext
                l = strlen(p);//l now holds the length of plaintext
                char c[l + 1];//c is a character array that holds the ciphertext
                printf("ciphertext: ");
                cipher(p, c, l, k);
            }
            //executes if the key is validated and incorrect probably because the key contains a number or a reapeated letter
            else
            {
                printf("Key must contain 26 unique alphabetical characters.\n");
                return 1;
            }
        }
        //executes if the key contains less than 26 characters or more
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
}
int i = 1;//i is used to index through the key but is ahead of j.used in the comparison of letters to ensure they are unique
int j = 0;//j is used to index through the key but is lagging i.used in the comparison of letters to ensure they are unique
//k is the string key
//l is the length of string key
int check(string k, int l)
{
    //base case for the main recursion that will end the whole recursion
    if (i == l)
    {
        return 1;
    }
    //base case for the minor recursion
    if (j == i)
    {
        i++;
        j = 0;
    }
    else
    {
        if (!isalpha(k[i]))
        {
            return 0;
        }
        else
        {
            if ((tolower(k[i]) != k[j]) && (toupper(k[i]) != k[j]))
            {
                j++;
                check(k, l);
            }
            else
            {
                return 0;
            }
        }

    }
    return check(k, l);
}
int h = 0, m = 0;
void cipher(string p, char c[], int l, string k)
{
    if (m == l)
    {
        c[m] = '\0';
        printf("%s\n", c);
        return;
    }

    else
    {
        if (isalpha(p[m]))
        {
            if (h == (tolower(p[m]) - 'a'))
            {
                if (islower(p[m]))
                {
                    c[m] = tolower(k[h]);
                }
                else
                {
                    c[m] = toupper(k[h]);
                }
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