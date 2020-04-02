#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Create command-line argument
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Check the character of command-line argument
    for (int m = 0, len = strlen(argv[1]); m < len; m++)
    {
        if (!isalpha(argv[1][m]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        else if (len != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    //Check if there is any repeated characters
    int count = 1;
    for (int n = 0; n < strlen(argv[1]); n++)
    {
        count = 1;
        for (int l = n + 1; l < strlen(argv[1]); l++)
        {
            if (argv[1][n] == argv[1][l])
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    //Get the plaintext
    string key = argv[1];
    string plaintext = get_string("plaintext: ");

    //Encrypt text
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = toupper(key[plaintext[i] - 65]);
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = tolower(key[plaintext[i] - 97]);
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;

}
