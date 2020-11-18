#include <stdio.h>
#include <string.h>
int hex2octc(char ch)
{
    switch (ch)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    }
    return 0;
}
int hex2oct(char *hex)
{
    int n = strlen(hex);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * 16 + hex2octc(hex[i]);
    }
    return ans;
}
int main(){
    char hex[100];
    scanf("%s", hex);
    printf("%d", hex2oct(hex));
}