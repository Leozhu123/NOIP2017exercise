#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int n, sum = 0;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    else
    {
        for (int i = 1; i <= n - 1; i++)
        {
            if (gcd(i, n - i) == 1)
                sum++;
        }
        cout << sum;
    }
}