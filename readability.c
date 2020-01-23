#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<math.h>
int count_letter(string x, int y);
int count_word(string x, int y);
int count_sentence(string x, int y);
void get_grade(int k, int l, int n);
int main(void)
{
    string s = get_string("Text: ");
    int l = 0;
    while(s[l] != '\0')
    {
        l++;
    }
    int letter = count_letter(s,l);
    int words = count_word(s,l);
    int sentence = count_sentence(s,l);
    get_grade(letter, words, sentence);
}
int count_letter(string x, int y)
{
    int letter = 0;
    for(int i = 0; i < y; i++)
    {
        if(isalpha(x[i]))
        {
            letter++;
        }
    }
    return letter;
}
int count_word(string x, int y)
{
    int words = 0;
    for(int i = 0; i < y; i++)
    {
        if(x[i] == ' ')
        {
            words++;
        }
        else
        {
            if(i == y-1)
            {
                words++;
            }
        }
    }
    return words;
}
int count_sentence(string x, int y)
{
    int sentence = 0;
    for(int i = 0; i < y; i++)
    {
        if(x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}
void get_grade(int k, int l, int m)
{
    float L = ((float)k * 100) / l;
    float S = ((float)m * 100) / l;
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
}