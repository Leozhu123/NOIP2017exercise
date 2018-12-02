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
const int maxn = 100005;
int n;
char str[maxn];
int posx[maxn],posy[maxn];
int dir[maxn];
set<P > s;
int ans=0;
int main(){
    freopen("dir.in","r",stdin);
    freopen("dir.out", "w", stdout);
    scanf("%s", str + 1);
    n=strlen(str+1);
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
    for(int i=1;i<=n;i++){
        if(str[i]=='F'){
            int dx = posx[n] - posx[i];
            int dy = posy[n] - posy[i];
            s.insert(P(posx[i] + dy - ddx[dir[i-1]], posy[i] - dx - ddy[dir[i-1]]));
            s.insert(P(posx[i] - dy - ddx[dir[i-1]], posy[i] + dx - ddy[dir[i-1]]));
        }
        if(str[i]=='R'){
            int dx = posx[n] - posx[i];
            int dy = posy[n] - posy[i];
            s.insert(P(posx[i] - dx,posy[i] - dy));
            s.insert(P(posx[i] - dy + ddx[dir[i - 1]], posy[i] + dx + ddy[dir[i - 1]]));
        }
        if(str[i]=='L'){
            int dx = posx[n] - posx[i];
            int dy = posy[n] - posy[i];
            s.insert(P(posx[i] - dx,posy[i] - dy));
            s.insert(P(posx[i] + dy + ddx[dir[i - 1]], posy[i] - dx + ddy[dir[i - 1]]));
        }
    }
    cout << s.size() << endl;
}