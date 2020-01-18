//This program prompts the user for his name and outputs hello + the user's name .
#include <stdio.h>
#include<cs50.h>
int main(void)
{
    //the printf function is responsible for outputting it's given parameter in this case it is hello + the user's input
    printf("hello, %s\n", get_string("What's your name?\n"));
}
