#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    long long n = get_long_long("Number: ");
    long long numberOG = n;
    long long dn = n;
    int len = 0;
    while (dn > 0)
    {
        dn = dn / 10;
        len++;
    }
    //printf("%d\n", len);
    int num[len];
    if ((len == 13) || (len == 15) || (len == 16))
    {

        for (int i = 0; i < len; i++)
        {
            int temp = (n % 10);
            num[i] = temp;
            n = n / 10;
        }
        //printf("Numbers added to array\n");
        //printf("Parsing evens... \n");
        int sumX = 0;
        for (int x = 1; x < len; x += 2)
        {

            int even = num[x] * 2;
            //printf("Even number = %d >> ", num[x]);
            //printf("x2 = %d\n", even);
            int lenE = 0;
            int lenHelp = even;
            while (lenHelp > 0)
            {
                lenHelp = lenHelp / 10;
                lenE++;
            }
            //printf("Even x2 Length: %d\n", lenE);
            if (lenE == 2)
            {
                int evenSplit[2];
                for (int y = 0; y < lenE; y++)
                {
                    evenSplit[y] = (even % 10);
                    //printf("Adding Split Even: %d\n", evenSplit[y]);
                    even = even / 10;
                    sumX += evenSplit[y];
                }
            }
            else if (lenE != 2)
            {
                sumX += even;
            }
            //printf("Working Split Even Sum: %d\n", sumX);
            //printf("----------------------------------\n");
        }
        //printf("-----------------\n");
        //printf("Total Split Even Sum: %d\n", sumX);

        //printf("Adding odds... \n");
        int oddSum = 0;
        for (int a = 0; a < len; a += 2)
        {
            //printf("Added: %d\n", num[a]);
            oddSum += num[a];
        }
        //printf("-------------\n");
        //printf("Odd Sum: %d\n", oddSum);

        int total = oddSum + sumX;
        //printf("Total: %d\n", total);

        if (total % 10 == 0)
        {
            //printf("Vaild... Final Provider Check... \n");
            if (((numberOG >= 340000000000000) && (numberOG < 350000000000000)) || ((numberOG >= 370000000000000)
                    && (numberOG < 380000000000000)))
            {
                printf("AMEX\n");
            }
            else if ((numberOG >= 5100000000000000) && (numberOG < 5600000000000000))
            {
                printf("MASTERCARD\n");
            }
            else if (((numberOG >= 4000000000000) && (numberOG < 5000000000000)) || ((numberOG >= 4000000000000000)
                     && (numberOG < 5000000000000000)))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
