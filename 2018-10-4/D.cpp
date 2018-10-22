#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<queue>
#define maxn 1000005
#define LL long long
using namespace std;
priority_queue <pair<LL,int>,vector<pair<LL,int> > > l;
priority_queue<pair<LL,int>,vector<pair<LL,int> > > r;
LL b[maxn];
LL n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        LL left, right;
        cin >> left >> right;
        l.push(make_pair(left,i));
        r.push(make_pair(right,i));
    }
    LL ans = 0;
    while (l.empty() != true) {
        LL left = l.top().first;
        LL right = r.top().first;
        LL i2 = r.top().second;
        LL remain = right;
        if (l.size() == 1) {
            ans += max(left, right);
            break;
        }
        if (l.top().second==r.top().second) {
            r.pop();
            LL right2 = r.top().first;
            ans += max(right2, left);
            r.pop();
            r.push(make_pair(remain,i2));
            l.pop();
        }
        else {
            ans += max(left, right);
            r.pop();
            l.pop();
        }
    }
    ans += n;
    cout << ans << endl;
}
