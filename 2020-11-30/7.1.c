#include <stdio.h>
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("gcd = %d\nlcm = %d", gcd(a, b), lcm(a, b));
}