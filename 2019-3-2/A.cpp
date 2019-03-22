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
#include <regex>
#include <sstream>
#define LL long long
#define P pair<int,int>
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
const int maxn = 1e6;
int main(){
    string str1("0|-?[1-9]\\d*");
    regex pattern1(str1, regex::icase);
    LL l,r,T;
    read(l,r,T);
    smatch result;
    for(int i=1;i<=T;i++){
        string str;
        cin>>str;
        if(regex_match(str,pattern1)){
            LL a = 0;
            stringstream ss(str);
            if(ss>>a && a>=l  && a<=r){
                cout << 0 << endl;
            }else{
                cout << 2 << endl;
            }
        }
        else{
            cout << 1 << endl;
        }
    }
}