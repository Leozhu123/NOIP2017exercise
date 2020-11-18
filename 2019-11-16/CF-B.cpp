//by ciwomuli
//AK JSOI 2019
//I love wyt
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#define LL long long
using namespace std;
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
const int maxn = 1e5 + 5;
int num[maxn], p[maxn], n;
bool in_off[maxn];
int ans[maxn], ans_cnt = 1, cnt,last_num;
set<int> today_in;
int main(){
    read(n);
    ans[0] = 0;
    for (int i = 1; i <= n;i++){
        int t=0;
        read(t);
        if(t >= 0){
            p[i] = 1;
            num[i] = t;
        }else{
            p[i] = -1;
            num[i] = -t;
        }
    }
    for (int i = 1; i <= n;i++)
    {
        if(p[i] == 1){
            if(in_off[num[i]] == true || today_in.count(num[i])) {
                //cout << i << endl;
                puts("-1");
                return 0;
            }
            today_in.insert(num[i]);
            in_off[num[i]] = true;
            cnt++;
        }else{
            if(in_off[num[i]] == false){
                //cout << i << endl;
                puts("-1");
                return 0;
            }
            in_off[num[i]] = false;
            cnt--;
//            cout << i << " " << cnt << endl;
            if(cnt == 0){
                ans[ans_cnt] = i - last_num;
                last_num = i;
                ans_cnt++;
                today_in.clear();
            }
        }
    }
    cout << ans_cnt - 1 << endl;
    for (int i = 1; i < ans_cnt;i++)
        cout << ans[i] << " ";
}