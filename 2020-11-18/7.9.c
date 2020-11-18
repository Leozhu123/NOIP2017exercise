#include <stdio.h>
void cnt(char *str, int *alpha, int *number, int *blank, int *other)
{
    *alpha = *number = *blank = *other = 0;
    for (int i = 0; str[i]; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            (*alpha)++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
            (*number)++;
        else if (str[i] == ' ')
            (*blank)++;
        else
            (*other)++;
    }
}
int main()
{
    char str[1000];
    gets(str);
    int a, n, b, o;
    cnt(str, &a, &n, &b, &o);
    printf("alpha=%d\nnumber=%d\nblank=%d\nother=%d", a, n, b, o);
}