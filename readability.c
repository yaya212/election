// the program determines the grade level of a given sentence, paragraph or even a page.
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
//function responsible for counting the number of words
void count(string x, int y, int *letter, int *words, int *sentence);
//function responsible for doing the calculation to determine the grade level
void get_grade(int *k, int *l, int *n);
int main(void)
{
    string s = get_string("Text: ");//s holds the input string
    int l = strlen(s);//l holds the length of string
    int letter = 0;//counter for the letters
    int words = 0;//counter for the words
    int sentence = 0;//counter for the sentences
    count(s, l, &letter, &words, &sentence);
    get_grade(&letter, &words, &sentence);
}
//x holds the string s
//y holds the length of string
int i = 0;
void count(string x, int y, int *letter, int *words, int *sentence)
{
    if (i == y)
    {
        return;
    }
    else
    {
        //given that each sentence ends with either '.' or '!' or '?'
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            (*sentence)++;
            //printf("Sentence(s) = %d\n", *sentence);
        }
        //checks is the character is an alphabet or not
        if (isalpha(x[i]))
        {
            (*letter)++;
            //printf("letter(s) = %d\n", *letter);
        }
        //given that words are separated with one space
        if (x[i] == ' ')
        {
            (*words)++;
            //printf("Word(s) = %d\n", *words);
            i++;
            count(x, y, letter, words, sentence);
        }
        else
        {
            if (i == y - 1)
            {
                (*words)++;
                //printf("Word(s) = %d\n", *words);
                i++;
                count(x, y, letter, words, sentence);
            }
            else
            {
                i++;
                count(x, y, letter, words, sentence);
            }
        }
    }

}
//k holds the number of letters
//l holds the number of words
//m holds the number of sentences
void get_grade(int *k, int *l, int *m)
{
    float L = ((float)(*k) * 100) / (*l);//L is the average number of letters per 100 words
    float S = ((float)(*m) * 100) / (*l);//S is the average number of sentences per 100 words
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