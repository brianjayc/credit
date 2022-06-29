#include <cs50.h>
#include <stdio.h>

int last_digit(long number)
{
    return number % 10; // modulo 10 to get remainder which equivalent to the last digit
}

int checksum(long number)
{
    int even = 0; // declare variable for the sum of even
    int odd = 0; // declare variable for the sum of odd

    while (number != 0) // loop until number is equal to zero
    {

        odd = odd + last_digit(number); // add last digit of number to odd

        number = number / 10; // proceed to next digit by dividing by 10, decimal will be truncated since this is a long type

        if ((last_digit(number) * 2) >= 10) // if last digit multiplied by 2 is greater than 10 get single digits and add it to even
        {
            even = even + last_digit(last_digit(number) * 2);
            even = even + last_digit((last_digit(number) * 2) / 10);
        }
        else
        {
            even = even + (last_digit(number) * 2); // if last digit multiplied by 2 is less than 10 add last digit to even
        }
        number = number / 10; // proceed to next digit
    }

    return last_digit(even + odd); // return last digit of the sum of odd and even
}

int main(void)
{
    long cc = get_long("Number: "); // get cc number

    if (checksum(cc) != 0) //checksum
    {
        printf("INVALID\n");
    }
    else if (cc >= 5100000000000000 && cc <= 5599999999999999) // check if master
    {
        printf("MASTERCARD\n");
    }
    else if ((cc >= 4000000000000000 && cc <= 4999999999999999) || (cc >= 4000000000000 && cc <= 4999999999999)) // check if visa
    {
        printf("VISA\n");
    }
    else if ((cc >= 340000000000000 && cc <= 349999999999999) || (cc >= 370000000000000 && cc <= 379999999999999))// check if amex
    {
        printf("AMEX\n");
    }
    else // anything else is invalid
    {
        printf("INVALID\n");
    }
}
