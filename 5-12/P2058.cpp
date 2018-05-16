#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
const int maxn = 100005;
using namespace std;
struct D
{
    int time;
    int k;
};
queue<D> q;
int maxpass = 0;
int passcnt[maxn];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        int time;
        cin >> time >> k;
        for (int i = 1; i <= k; i++)
        {
            D dd;
            dd.time=time;
            cin >> dd.k;
            maxpass = max(maxpass, dd.k);
            if(passcnt[dd.k]==0)
                ans++;
            passcnt[dd.k]++;
            q.push(dd);
        }
        while (!q.empty())
        {
            D tmp = q.front();
            if (tmp.time <= time - 86400)
            {
                q.pop();
                passcnt[tmp.k]--;
                if(passcnt[tmp.k]==0)
                    ans--;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
}