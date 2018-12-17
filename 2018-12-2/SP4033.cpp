#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#define LL long long
#define P system("pause")
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
const int maxn=100001;
string s[maxn];
int main(){
	int n,k;
	read(k);
	while(k--){
		bool flag=false;
		read(n);
		for(int i=1;i<=n;i++) cin>>s[i];
		sort(s+1,s+n+1);
		for(int i=1;i<=n-1;i++){
			if(s[i+1].find(s[i],0)==0){
				flag=true;
				break;
			}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
}
