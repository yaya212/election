#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<math.h>
int main(void)
{
    string s = get_string("Text: ");
    int letter = 0;
    int words = 0;
    int sentence = 0;
    int l = 0;
    while(s[l] != '\0')
    {
        l++;
    }
    for(int i = 0; i < l; i++)
    {
        if(isalpha(s[i]))
        {
            letter++;
        }
        if(s[i] == ' ')
        {
            words++;
        }
        else
        {
            if(i == l-1)
            {
                words++;
            }
        }
        if(s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentence++;
        }
    }
    float L = (letter * 100) / words;
    float S = (sentence * 100) / words;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n",index);
    }
    //printf("%d letter(s)\n%d word(s)\n%d sentence(s)\n",letter,words,sentence);
}