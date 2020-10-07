#include <stdio.h>
#include <cs50.h>

//program prompts user for input
/* HELLO, WORLD
    My hello,
    World in C
    Typography
    Hours of text on a screen
    A poem
    A matrix
    An android
    */

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}