#include "stdio.h"
char s1[105], s2[105];
int main()
{
    scanf("%s", s1);
    for (int i = 0; s1[i]; i++)
    {
        s2[i] = s1[i];
        s2[i + 1] = '\0';
    }
    printf("%s", s2);
}