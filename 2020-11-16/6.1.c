#include "stdio.h"
int a[105];
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        a[i] = 1;
    }
    a[1] = 0;
    for (int i = 2; i <= 100; i++)
    {
        if (a[i])
        {
            printf("%d\n", i);
            for (int k = 2; k * i <= 100; k++)
                a[i * k] = 0;
        }
    }
}