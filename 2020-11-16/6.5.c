#include "stdio.h"
int a[105];
int b[105];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        b[n - i + 1] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", b[i]);
    }
}