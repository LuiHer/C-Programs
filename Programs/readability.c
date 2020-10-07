#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Declaration of functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void printText(int index);

//Part 2 and 3 : Word and sentence counting
int main(void)
{
    string Uinput = get_string("Text: ");

//count text elements using functions
    float lettersN = count_letters(Uinput);
    float wordsN = count_words(Uinput);
    float sentencesN = count_sentences(Uinput);

//Calculate formula parameters where:
//L = average number of letters per 100 words
//S = average number of sentences per 100 words
    float L = (lettersN / wordsN) * 100;
    float S = (sentencesN / wordsN) * 100;

//Calculate Coleman-Liau index. Outputs U.S. grade level of text

    int index = round(0.0588 * L - 0.296 * S - 15.8);

//Print grade level based on index calculation.
    printText(index);



}
//FUNCTIONS

//Count letters (alphabetic characters in text)
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < (strlen(text)); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }

    }
    return count;
}

//Count words (strings separated by space)
int count_words(string text)
{
    int count = 1;
    for (int i = 0; i < (strlen(text)); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }

    }
    return count;
}

//Count sentences (ending in . ! or ?)
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < (strlen(text)); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }

    }
    return count;
}

//Prints garde level based on calculated index
void printText(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %d\n", index);
    }

}
//REFERENCE

/*
Coleman-Liau index: outputs U.S. grade level of text
index = 0.0588 * L - 0.296 * S - 15.8

L: average number of letters per 100 words
S: average number of sentences per 100 words

IMPORTANT NOTE:
Recall that, when dividing values of type int in C, the result will also be an int,
with any remainder (i.e., digits after the decimal point) discarded. Put another way,
the result will be “truncated.” You might want to cast your one or more values to float
before performing division when calculating L and S!

*/
//___________________________________________

//INTER-VERSIONS: steps to full program

/*
//Part 0: User Input
int main(void)
{
  string text = get_string("Text: ");
  printf("%s\n", text);
}

----------------------------

//Part 1: Letter counting
int main(void)
{
  string text = get_string("Text: ");
  printf("%d letter(s)\n", count_letters(text));
}

int count_letters(string textCount)
{
    int count = 0;
    for (int i = 0;i < (strlen(textCount)); i++)
    {
        if(isalpha(textCount[i]))
        {
           count++;
        }

    }
    return count;
}

-------------------------------------------------
//Part 2 and 3 : Word and sentence counting
int main(void)
{
  string Uinput = get_string("Text: ");
  printf("%d letter(s)\n", count_letters(Uinput));
  printf("%d word(s)\n", count_words(Uinput));
  printf("%d word(s)\n", count_sentences(Uinput));
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0;i < (strlen(text)); i++)
    {
        if (isalpha(text[i]))
        {
           count++;
        }

    }
    return count;
}

int count_words(string text)
{
    int count = 1;
    for (int i = 0;i < (strlen(text)); i++)
    {
        if (text[i] == ' ')
        {
           count++;
        }

    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0;i < (strlen(text)); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
           count++;
        }

    }
    return count;
}
*/