#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    do
    {
        n = get_float("Change: ");
    }
    while (n < 0);

//To change the dollars into cents:
    int i = round(n * 100);
  
    int coint_ammount = 0;
//When over a quarter, subtract and add 1 to variable coint_ammount
    while (i >= 25)
    {
        i -= 25,
        coint_ammount++;
    }
//When over a dime, subtract and add 1 to variable coint_ammount
    while (i >= 10)
    {
        i -= 10,
        coint_ammount++;
    }
//When over a nickel, subtract and add 1 to variable coint_ammount
    while (i >= 5)
    {
        i -= 5,
        coint_ammount++;
    }
//When over a penny, subtract and add 1 to variable coint_ammount
    while (i >= 1)
    {
        i -= 1,
        coint_ammount++;
    }
    printf("%i\n", coint_ammount);    
}
