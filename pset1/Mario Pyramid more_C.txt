//Mario assignment - more

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
//Outer loop to create rows:    
    for (int i = 0; i < n; i++)
    {
//1st inner loop to create number of spaces on the left:
        for (int t = n - i - 2; t >= 0; t = t - 1)
        {
            printf(" ");
        }
//2nd inner loop to create the left side of the pyramid:        
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
//Function to print the spaces in between:        
        {
            printf("  ");
        }
//3rd inner loop to create the right side of the pyramid:       
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}