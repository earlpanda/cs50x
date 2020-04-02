//I came back to solve credit after week 6
//so this might be difficult to someone who just started at week 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 16

int main(void)
{
    char str[256];
    printf("Enter your card number: ");
    scanf("%s", str);

    //get length of string card number
    int length = strlen(str);

    //convert sring to array of integer
    int cardnum[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        cardnum[i] = str[i] - '0';
    }

    //variables
    int sum = 0;
    int parity = length % 2;

    //checksum
    for (int i = 0; i < length; i++)
    {
        int digit = cardnum[i];
        if (i % 2 == parity)
        {
            digit *= 2;
        }
        if (digit > 9)
        {
            digit -= 9;
        }
        sum += digit;
    }

    //check what kind of credit card is it
    if (length < 13 || length > 16)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (cardnum[0] == 5 && (cardnum[1] == 1 ||
                                 cardnum[1] == 2 || cardnum[1] == 3 || cardnum[1] == 4 ||
                                 cardnum[1] == 5) && length == 16)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if (cardnum[0] == 3 && (cardnum[1] == 4 || cardnum[1] == 7) && length == 15)
    {
        printf("AMEX\n");
        return 0;
    }
    else if (cardnum[0] == 4 && length == 16)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
