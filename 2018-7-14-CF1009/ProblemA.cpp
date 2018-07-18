#include <iostream>
#include <queue>
using namespace std;
int a[1005];
int main(){
    queue<int> q;
    int n,m;
    int ans = 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        q.push(t);
    }
    for(int i=1;i<=n;i++){
        int x=q.front();
        if(x>=a[i]) {
            ans++;
            q.pop();
        }
    }
    cout << ans;
}