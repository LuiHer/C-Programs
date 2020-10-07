#include <stdio.h>
#include <cs50.h>

/*This program takes a height input
and builds a text-based pyramid of that height
*/

int main(void)
{
    int height = 0;

//Exception checker. Number must be int between 0 and 8.
    do
    {
        float x = get_int("Height:");
        height = x;
    }
    while (height <= 0 || height > 8);

    int counter = height;

//Pyramid Builder
    if (height >= 1 && height <= 8)
    {
        while (counter > 0)
        {
//Leading space
            for (int i = 1; i < counter; i++)
            {
                printf(" ");
            }
//First # block
            for (int i = counter; i <= height; i++)
            {
                printf("#");
            }
//Double blank space
            printf("  ");
//Second # block
            for (int i = counter; i <= height; i++)
            {
                printf("#");
            }


            printf("\n");
            counter--;

        }

    }
}
