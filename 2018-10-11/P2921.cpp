#include <iostream>
using namespace std;
const int maxn=100005;
int n;
int nxt[maxn];
int color[maxn];
int sucdfn[maxn];
int dfn[maxn];
int minc[maxn];
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> nxt[i];
    }
    for (int cow = 1; cow <= n;cow++){
        for (int i = cow, cnt = 0;;i=nxt[i],++cnt){
            if(!color[i]){
                color[i] = cow;
                dfn[i] = cnt;
            }else if(color[i]==cow){
                minc[cow] = cnt - dfn[i];
                sucdfn[cow] = dfn[i];
                cout << cnt << endl;
                break;
            }else {
                minc[cow] = minc[color[i]];
                sucdfn[cow] = cnt + max(sucdfn[color[i]] - dfn[i], 0);
                cout << sucdfn[cow] + minc[cow] << endl;
                break;
            }
        }
    }
}