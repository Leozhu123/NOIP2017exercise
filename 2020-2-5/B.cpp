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
const int maxn = 105;
int n,m;
string ss[maxn];
bool used[maxn];
bool isp(string s){
    bool b = true;
    for (int i = 0; i < s.size();i++){
        if(s[i] != s[s.size()- i-1])
            b = false;
    }
    return b;
}
bool is2p(string s1,string s2){
    bool b = true;
    for (int i = 0; i < s1.size();i++){
        if(s1[i] != s2[s1.size()- i-1])
            b = false;
    }
    return b;
}
string rev(string s){
    string ans;
    for (int i = s.size() - 1; i >= 0;i--){
        ans += s[i];
    }
    return ans;
}
int main(){
    read(n,m);
    for(int i=1;i<=n;i++){
        cin >> ss[i];
    }
    int cnt = 0;
    string ans1;
    for (int i = 1;i<=n;i++){
        for (int j = i + 1;j<=n;j++){
            if(!used[i] && !used[j] && is2p(ss[i],ss[j])){
                cnt += 2;
                used[i] = true;
                used[j] = true;
                ans1 += ss[i];
            }
        }
    }
    string ans;
    bool a = false;
    for (int i = 1;i<=n;i++){
        if(!used[i] && isp(ss[i])){
            ans = ans1 + ss[i];
            ans += rev(ans1);
            a = true;
        }
    }
    if(a){
        cout << (cnt + 1) * m << endl
             << ans;
    }else{
        cout << cnt  * m<< endl
             << ans1 + rev(ans1);
    }
}