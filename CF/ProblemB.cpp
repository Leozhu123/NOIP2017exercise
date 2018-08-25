#include <iostream>
#define LL long long
using namespace std;
int a[100005], b[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        a[i] = ch - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        b[i] = ch - '0';
    }
    LL cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            cnt1++;
        if (a[i] == 0 && b[i] == 0)
            cnt2++;
        if (a[i] == 1 && b[i] == 0)
            cnt3++;
        if (a[i] == 0 && b[i] == 1)
            cnt4++;
    }
    cout << cnt1 * cnt2 + cnt3 * cnt4;
}