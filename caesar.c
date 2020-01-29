//This program encodes a message given using the provided key
#include<stdio.h>
#include<cs50.h>
#include<string.h>//used to acces the strlen() function
#include<ctype.h>//used to acces the isalpha(), isdigit(), isupper() and islower() functions
#include <stdlib.h>//used to access the atoi() funcation which converts from string to integer
int check(string x, int y);//used to validate the key provided by the user
void cipher(string p, char c[], int d, int l);//used to encode the message(plaintext) using the given key
//argc here represents the number of words in the command line include the ./program name
//argv[] is an array of strings that contains the words written in the command line including the ./program name
int main(int argc, string argv[])
{
    //check if there are less than 2 arguments or more to prompt the user as follows and exit the program with a return value of 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //if there are exactly 2 arguments including the ./program name
    else
    {
        string k = argv[argc - 1];//k holds the key
        int l = strlen(k);//l holds the length of the key string
        int f = check(k, l);//f holds the return value of the validation of key
        //this condition executes if the key is validated and is in the correct format
        if (f == 1)
        {
            int d = atoi(k);//d holds the equivalent number for the string key
            string p = get_string("plaintext: ");//p holds the plaintext provided by the user
            l = strlen(p);//l now holds the length of the plaintext
            char c[l + 1];//c is an array of characters that holds the ciphertext
            printf("ciphertext: ");
            cipher(p , c, d, l);
            return 0;
        }
        //this condition executes if the key is validated and not in the correct format
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
}
int i = 0;
//x holds the string key
//y holds the lengt of string key
int check(string x, int y)
{
    //returns 0 indicating wrong format is the key start with -ve sign
    //base condition 1
    if (x[0] == '-')
    {
        return 0;
    }
    //returns 1 indicating the format is correct if the key reaches it length without being a letter or any symbol and +ve value
    //base condition 2
    if (i == y)
    {
        return 1;
    }
    else
    {
        //executes and returns 0 if the key is not fully a number
        if (!isdigit(x[i]))
        {
            return 0;
        }
        //executes and the function calls itself recursively
        else
        {
            i++;
            return check(x, y);
        }
    }
}
int j = 0;
//p holds the plaintext
//c is the array of characters that hold the ciphertext
//d is the key after being converted into an integer
//l is the length of plaintext
void cipher(string p, char c[], int d, int l)
{
    //executes if the program reaches the end of the plaintext and ends the recursion
    //base case
    if (j == l)
    {
        c[j] = '\0';
        printf("%s\n", c);
        return;
    }
    //executes if the program hasn't still reached the end of the plaintext
    else
    {
        //checks if the current character of the plaintext is an alphabet
        if (isalpha(p[j]))
        {
            //checks if the current character in the plaintext is uppercase
            if (isupper(p[j]))
            {
                c[j] = 'A' + ((p[j] - 'A' + d) % 26);
            }
            //checks if the current character in the plaintext is lowercase
            else if (islower(p[j]))
            {
                c[j] = 'a' + ((p[j] - 'a' + d) % 26);
            }
        }
        //executes if the current character is a symbol or number(non alphabetical character)
        else
        {
            c[j] = p[j];
        }
        j++;
        cipher(p, c, d, l);
    }
}