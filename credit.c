#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get user input
    long long input;
    do
    {
        input = get_long_long("Number: ");
    }
    while (input < 0);

    //check if digit length is correct
    int len = 0;
    long long digits = input;
    while (digits >= 1)
    {
        digits /= 10;
        len ++; //len will now be the length of digits
    }

    int cardnumber[len]; // declare array
    for (int i = 0; i < len; i++) //puts all digits into indexes from last to first
    {
        cardnumber[i] = input % 10;
        input /= 10;
    }

    int interdigs = 1;
    int dobdigs;
    int sumdobdigs = 0;
    while (interdigs < len)
    {
        dobdigs = cardnumber[interdigs] * 2; //doubles every other digit starting second to last
        if (dobdigs > 9)
        {
            dobdigs = dobdigs % 10; //splits digits
            sumdobdigs ++;
        }
        sumdobdigs += dobdigs;
        interdigs += 2;
    }

    int oddinterdigs = 0;
    int sumodddigs = 0;
    while (oddinterdigs < len)
    {
        sumodddigs += cardnumber[oddinterdigs]; //sum of every of the other digits
        oddinterdigs += 2;
    }

    int totalsum = sumdobdigs + sumodddigs; //total sum

    if (len != 15 && len != 13 && len != 16) //checks length
    {
        printf("INVALID\n");
    }
    else if (totalsum % 10 != 0) //checks whether sum ends in 0
    {
        printf("INVALID\n");
    }
    else if (len == 15) //checks if AMEX
    {
        if ((cardnumber[len - 1] == 3 && cardnumber[len - 2] == 4) || (cardnumber[len - 1] == 3 && cardnumber[len - 2] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (len == 16)
    {
        if (cardnumber[len - 1] == 4) //checks if VISA
        {
            printf("VISA\n");
        }
        else if (cardnumber[len - 1] == 5 && (cardnumber[len - 2] == 1 || cardnumber[len - 2] == 2 || cardnumber[len - 2] == 3
                                              || cardnumber[len - 2] == 4 || cardnumber[len - 2] == 5)) //checks if MC
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (len == 13 && cardnumber[len - 1] == 4) //checks if VISA
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

