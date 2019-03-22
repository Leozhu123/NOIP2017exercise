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
int T;
const LL P = 998244353;
LL fast_pow(LL a,LL x){
    LL now=a;
    LL ans=1;
    while(x){
        if(x&1) ans=(ans % P * now % P) % P;
        now=(now % P * now % P) % P;
        x>>=1;
    }
    return ans % P;
}
bool isysf(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
LL getd(string str,LL x){

}
LL getf(string str,LL x){
    if (str[0]=='(' && str[str.size()-1]==')')
        return getf(str.substr(1, str.size() - 2), x);
    for(int  i=0;i<str.size();i++){
        if(isysf(str[i])){
            if(str[i]=='+'){
                return getf(str.substr(0,i-1),x) + getf(str.substr(0,i-1),x)
            }
        }
    }
}
int main(){
    read(T);
    for(int i=1;i<=T;i++){
        string str;
        cin>>str;
        LL a,b;
        read(a, b);
        cout << paser_exp(str, a) << " " << paser_exp(str, b) << endl;
    }
}