#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;

    // Get a positive long from the user
    do
    {
        card = get_long("Card number: ");
    }
    while (card < 0);

    int sum1 = 0;
    int sum2 = 0;
    int digit;
    int length = 0;
    long temp_card = card;

    while (temp_card > 0)
    {
        digit = temp_card % 10;

        if (length % 2 == 0)
        {
            sum1 += digit;
        }
        else
        {
            digit *= 2;
            sum2 += digit / 10 + digit % 10;
        }

        temp_card /= 10;
        length++;
    }

    int sum = sum1 + sum2;

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (length == 15 && (temp_card == 34 || temp_card == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 13 || length == 16) && (temp_card >= 40 && temp_card <= 49))
        {
            printf("VISA\n");
        }
        else if (length == 16 && (temp_card >= 51 && temp_card <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    return 0;
}
