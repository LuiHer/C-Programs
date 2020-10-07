#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
//Count command-line arguments
    if (argc == 2)
    {

//Check key is only digits
        for (int c = 0; c < strlen(argv[1]); c++)
        {
            if (!(isdigit(argv[1][c])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
//convert string to int and return
        printf("Success\n");
        int k = atoi(argv[1]);
        printf("%i\n", k);

//Prompt user for text
        string plaintext = get_string("plaintext: ");

//Iterate over chars to rotate them
        int ciphertext[(strlen(plaintext))];
        for (int c = 0; c < (strlen(plaintext)); c++)
        {
            //check if alphabetical
            if (isalpha(plaintext[c]))
            {
                //rotate based on case using ASCII code
                //upper case wrap-around
                if (isupper(plaintext[c]))
                {
                    ciphertext[c] = (((plaintext[c] - 65) + k) % 26) + 65;
                }
                //lower case wrap-around
                else if (islower(plaintext[c]))
                {
                    ciphertext[c] = (((plaintext[c] - 97) + k) % 26) + 97;
                }
                //print with rotation

            }
            //if not alphabetical, print unchanged
            else
            {
                ciphertext[c] = plaintext[c];
            }
        }
        //convert back to string
        char str[(strlen(plaintext))];
        for (int j = 0; j < (strlen(plaintext)); j++)
        {
            sprintf(&str[j], "%c", ciphertext[j]);
        }
        //print ciphertext
        printf("ciphertext: %s\n", str);
    }
    else
    {
        return 1;
    }
}

/*
--------------------
HISTORICAL

VERSION 1: Count Arguments
//Count command-line arguments. Print first argument
int main(int argc, char *argv[])
{
//Count command-line arguments
  if(argc == 2)
  {
    printf("Success\n");
    printf("%s\n", argv[1]);
  }
  else
  {
   printf("Usage: ./caesar key, %d\n", argc);
  }
}

-----------------------------------
VERSION 2: Validating the key
int main(int argc, string argv[])
{
//Count command-line arguments
  if(argc == 2)
  {

 //Check key is only digits
    for(int c = 0; c < strlen(argv[1]); c++)
    {
        if(!(isdigit(argv[1][c])))
        {
            printf("%d\n", isdigit(argv[1][c]));
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
//convert string to int and return
    printf("Success\n");
    int converted = atoi(argv[1]);
    printf("%i\n", converted);
  }
}

//ITERATE OVER CHARS AND ROTATE
//This version does not save all to cipher text
//Iterate over chars to rotate them
    printf("ciphertext: ");
    for(int c = 0; c < (strlen(plaintext)); c++)
    {
        //check if alphabetical
        if(isalpha(plaintext[c]))
        {
            //rotate based on case using ASCII code
            //upper case wrap-around
            if(isupper(plaintext[c]))
            {
                printf(("%c",((((plaintext[c] - 65) + k) % 26) + 65));
            }
            //lower case wrap-around
            else if(islower(plaintext[c]))
            {
                printf(("%c",((((plaintext[c] - 97) + k) % 26) + 97)));
            }
            //print with rotation

        }
        //if not alphabetical, print unchanged
        else
        {
            printf(printf("%c",plaintext[c]);
        }
      //plaintext[c] += k;

    }
    printf(" \n");
  }
}

*/