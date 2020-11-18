//by ciwomuli
//AK JSOI 2019
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
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
string str1, str2;
int main()
{
    cin >> str1;
    for (int i = 0; i < str1.size(); i++)
        if (str1[i] != 'a')
            str2.push_back(str1[i]);
    int m = str2.size() / 2;
    if(str2.size() % 2 == 1){
        puts(":(");
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < m;i++) if(str2[i] != str2[i+m])
        ok = false;
    if(!ok){
        puts(":(");
        return 0;
    }
    int p = 0;
    int cnt = 0;
    string ans;
    if(m == 0){
        cout<<str1;
        return 0;
    }
    while(cnt < m){
        ans.push_back(str1[p++]);
        if(str1[p - 1] != 'a')
            cnt++;
    }
    while(str1[p] == 'a'){
        ans.push_back(str1[p++]);
    }
    for (int i = p;i<str1.size();i++) {
        if(str1[i] == 'a')
            ok = false;
    }
    if(!ok){
        puts(":(");
        return 0;
    }
    cout << ans;
}