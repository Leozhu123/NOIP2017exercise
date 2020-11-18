#include <stdio.h>
int main()
{
    int first = 1;
    int a, b, c;
    for (a = 0; a <= 20; a++)
    {
        for (b = 0; b <= 34; b++)
        {
            for (c = 0; c <= 300; c++)
            {
                if (a + b + c == 100 && c % 3 == 0 && a * 5 + b * 3 + c / 3 == 100)
                {
                    if (first)
                    {
                        first = 0;
                    }
                    else
                    {
                        printf(",");
                    }
                    printf("%d,%d,%d", a, b, c);
                }
            }
        }
    }
    return 0;
}