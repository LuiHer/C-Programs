#include <stdio.h>
#include <cs50.h>
#include <math.h>

//adding a comment for good measure

int main(void)
{
    float dollars = 0.0;

    do
    {
        float x = get_float("Change owed:");
        dollars = x;
    }

    while (dollars <= 0);


//keep asking while not positive int
    int pay = round(dollars * 100);
    int change = 0;

//iterate through coins to get max

    while (pay > 0)
    {
        while (pay / 25 >= 1)
        {
            change++;
            pay = pay - 25;
        }
//printf("%f\n", pay);
        while (pay / 10 >= 1)
        {
            change++;
            pay = pay - 10;
        }
//printf("%f\n", pay);
        while (pay / 5 >= 1)
        {
            change++;
            pay = pay - 5;
        }
        while (pay / 1 >= 1)
        {
            change++;
            pay = pay - 1;
        }
        break;
    }



    printf("%d\n", change);

}