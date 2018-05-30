#include <iostream>
using namespace std;
const int maxn = 105;
long long a[maxn];
long long  n;
int main()
{
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}