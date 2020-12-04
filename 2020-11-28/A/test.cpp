#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, z, y, k;
    scanf("%d%d%d%d", &a, &b, &z, &y);
    if (2 * z < y)
    {
        if (a > b)
        {
            k = ((fabs(a - b) - 1) * 2 + 1) * z;
        }
        if (a == b)
            k = z;
        if (a < b)
            k = (fabs(a - b) * 2 + 1) * z;
    }
    else
    {
        if (a > b)
        {
            k = (fabs(a - b) - 1) * z + y;
        }
        if (a == b)
            k = z;
        if (a < b)
            k = fabs(a - b) * y + z;
    }
    printf("%d\n", k);
    return 0;
}