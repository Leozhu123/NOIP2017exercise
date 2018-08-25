#include <iostream>
using namespace std;
int p[1005];
bool vis[1005];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    for(int i=1;i<=n;i++){
      //  cout << i << endl;
        for(int j=1;j<=n;j++){
            vis[j] = false;
        }
        int now = i;
        vis[now] = true;
        for(int j=1;j<=n;j++){
            now = p[now];
        //    cout << now << endl;
            if(vis[now]) {
                cout<<now<<" ";
                break;
            }
            vis[now]=true;
        }
    }
}