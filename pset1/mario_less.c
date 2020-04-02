//Mario assignment - less

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    
//The outer loop to create number of rows:
    for (int i = 0; i < n; i++)
    {
//The 1st inner loop to create the right number of spaces:
        for (int t = n - i - 2; t >= 0; t = t - 1)
        {
            printf(" ");
        }
//The 2nd inner loop to create hashes:
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
