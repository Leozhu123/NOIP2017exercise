#include <iostream>
using namespace std;
const int maxn=100005;
int fa[maxn*3];
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
int n,m,a,b,c;
int ans = 0;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n * 3;i++){
        fa[i] = i;
    }
    for (int i = 1; i <= m;i++){
        cin >> a >> b >> c;
        if(b>n || c>n)
            ans++;
        else{
            if(a==1){
                if(find(b+n)==find(c) || find(b) == find(c+n))
                    ans++;
                else{
                    fa[find(b)] = fa[find(c)];
                    fa[find(b + n)] = fa[find(c + n)];
                    fa[find(b + 2 * n)] = fa[find(c + 2 * n)];
                }
            }else{
                if(find(b)==find(c) || find(b)==find(c+n))
                    ans++;
                else{
                    fa[find(b+n)]=fa[find(c)];
                    fa[find(b + n * 2)] = fa[find(c + n)];
                    fa[find(b)] = fa[find(c + n * 2)];
                }
            }
        }
    }
    cout << ans;
}