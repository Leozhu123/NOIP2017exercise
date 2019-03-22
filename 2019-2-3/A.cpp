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
bool isv(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(){
    bool ok=true;
    string str1,str2;
    cin>>str1>>str2;
    if(str1.size()!=str2.size()){
        puts("No");
        return 0;
    }
    for (int i = 0; i < str1.size();i++){
        if(isv(str1[i]) != isv(str2[i])  )
            ok = false;
    }
    if(ok) puts("Yes");
    else
        puts("No");
}