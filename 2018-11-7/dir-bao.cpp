#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
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
const int ddx[4]={0,1,0,-1};
const int ddy[4]={1,0,-1,0};
const char ccc[3] = {'F', 'L', 'R'};
const int maxn = 100005;
int n;
char str[maxn];
int posx[maxn],posy[maxn];
int dir[maxn];
set<P > s;
int ans=0;
void qiu(){
    posx[0]=posy[0]=0;
    dir[0] = 0;
    for(int i=1;i<=n;i++){
        if(str[i]=='F'){
            dir[i] = dir[i - 1];
            posx[i]=posx[i-1]+ddx[dir[i]];
            posy[i]=posy[i-1]+ddy[dir[i]];
        }else{
            posx[i]=posx[i-1];
            posy[i]=posy[i-1];
            if(str[i]=='R'){
                dir[i]=(dir[i-1]+1)%4;
            }else{
                dir[i]=(dir[i-1]+3)%4;
            }
        }
    }
}
int main(){
    scanf("%s", str + 1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++){
        char tmp = str[i];
        for(int j=0;j<3;j++){
            if(ccc[j]==tmp)
                continue;
            str[i] = ccc[j];
            qiu();
            s.insert(P(posx[n], posy[n]));
        }
        str[i] = tmp;
    }
    cout << s.size() << endl;
}