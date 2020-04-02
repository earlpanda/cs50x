//CS50 Caesar 

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function declaration
int upper(int p, int k);
int lower(int p, int k);

//Create command-line argument
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Check if character of command-line argument is decimal digit
    for (int m = 0, len = strlen(argv[1]); m < len; m++)
    {
        if (!isdigit(argv[1][m]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Convert string to int
    int k = atoi(argv[1]);

    if (k >= 0)

    {
        //Get the plaintext
        string text = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, n = strlen(text); i < n; i++)
        {
            //checking if it is alphabetic character -> uppercase or lowercase
            if (islower(text[i]))
            {
                printf("%c", lower(text[i], k));
            }

            else if (isupper(text[i]))
            {
                printf("%c", upper(text[i], k));
            }

            //if not, leave as it is
            else
            {
                printf("%c", text[i]);
            }
        }

        printf("\n");

    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    return 0;

}

//write a function that c = (p + k)%26
int lower(int p, int k)
{
    int c = ((p + k - 97) % 26) + 97;
    return c;
}

int upper(int p, int k)
{
    int c = ((p + k - 65) % 26) + 65;
    return c;
}

