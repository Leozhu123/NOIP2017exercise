#include <iostream>
using namespace std;
const int maxn=50005;
const int inf = 1000000;
int a[maxn];
int ans[maxn];
int n, d;
bool check(int x){
    int cnt = 1;
    int tmp = 0;
    for (int i = 1; i <= d;i++){
        while(tmp<x){
            if(cnt>n)
                return false;
            tmp+=a[cnt];
            ans[cnt] = i;
            cnt++;
        }
  //      cout << i << " " << tmp << endl;
        tmp = tmp / 2;
    }
    return true;
}
int main(){
    cin>>n>>d;
    for (int i = 1;i<=n;i++){
        cin >> a[i];
    }
    int l=1;
    int r=inf;
    while(r-l>5){
        int mid=(l+r)>>1;
    //    cout << check(mid) << " " << mid << endl;
       // cout << mid << endl;
        if(check(mid)){
            l = mid;
        }else{
            r = mid-1 ;
        }
    }
    int i=r;
    for (int i = r; i >= l;i++){
        if(check(i))
            break;
    }
    cout << i << endl;
    for (int i = 1; i <= d;i++){
        cout << ans[i] << endl;
    }
}