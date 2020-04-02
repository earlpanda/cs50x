//Readability

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)

{
    //Get user's input text:

    string text = get_string("Text: ");

    //Count number of letters, words and sentences:

    int letters = 0, words = 1, sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isalpha(text[i]))
        {
            letters++;
        }

        else if (isspace(text[i]))
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //Build the Coleman-Liau index based on formula:

    float L = 100 / (float)words * (float)letters;
    float S = 100 / (float)words * (float)sentences;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    //Check the index number and give the output:

    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %d\n", (int)round(index));
    }

    return 0;

}