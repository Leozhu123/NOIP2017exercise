#include <iostream>
using namespace std;
const int maxn = 2000005;
int rest[maxn],diff[maxn],need[maxn],d[maxn],l[maxn],r[maxn];
int n, m;
bool check(int x){
    for(int i=1;i<=n;i++){
        diff[i] = 0;
    }
    for (int i = 1; i <= x;i++){
        diff[l[i]]+=d[i];
        diff[r[i] + 1] -= d[i];
    }
    need[0] = 0;
    for (int i = 1; i <= n;i++){
        need[i] = need[i - 1] + diff[i];
        if(need[i]>rest[i])
            return false;
    }
    return true;
}
int main(){
    cin>>n>>m;
    for (int i = 1; i <= n;i++){
        cin >> rest[i];
    }
    for (int i = 1; i <= m;i++){
        cin >> d[i] >> l[i] >> r[i];
    }
    int begin=1,end=m;
    if(check(m)){
        cout<<"0";
        return 0;
    }
    while(begin<end)
    {
        int mid=(begin+end)/2;
        if(check(mid))begin=mid+1;
        else end=mid;
    }
    cout << -1 << endl
         << begin;
}
