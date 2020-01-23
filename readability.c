// the program determines the grade level of a given sentence, paragraph or even a page.
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<math.h>
//function responsible for counting the number of letters
int count_letter(string x, int y);
//function responsible for counting the number of words
int count_word(string x, int y);
//function responsible for counting the number of sentences
int count_sentence(string x, int y);
//function responsible for doing the calculation to determine the grade level
void get_grade(int k, int l, int n);
int main(void)
{
    string s = get_string("Text: ");//s holds the input string
    int l = 0;//l is used to count determine the length of that string
    //loop responsible for counting the number of characters in the string s given that the last character in any string is the '\0'
    while (s[l] != '\0')
    {
        l++;
    }
    int letter = count_letter(s, l);
    int words = count_word(s, l);
    int sentence = count_sentence(s, l);
    get_grade(letter, words, sentence);
}
//x holds the string s
//y holds the length of string
int count_letter(string x, int y)
{
    int letter = 0;//counter for the letters
    for (int i = 0; i < y; i++)
    {
        //checks is the character is an alphabet or not
        if (isalpha(x[i]))
        {
            letter++;
        }
    }
    return letter;
}
//x holds the string s
//y holds the length of string
int count_word(string x, int y)
{
    int words = 0;//counter for the words
    for (int i = 0; i < y; i++)
    {
        //given that words are separated with one space
        if (x[i] == ' ')
        {
            words++;
        }
        else
        {
            if (i == y - 1)
            {
                words++;
            }
        }
    }
    return words;
}
//x holds the string s
//y holds the length of string
int count_sentence(string x, int y)
{
    int sentence = 0;//counter for the sentences
    for (int i = 0; i < y; i++)
    {
        //given that each sentence ends with either '.' or '!' or '?'
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}
//k holds the number of letters
//l holds the number of words
//m holds the number of sentences
void get_grade(int k, int l, int m)
{
    float L = ((float)k * 100) / l;//L is the average number of letters per 100 words
    float S = ((float)m * 100) / l;//S is the average number of sentences per 100 words
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);//index holds the grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}