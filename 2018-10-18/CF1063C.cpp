#include <iostream>
#include <string>
#include <set>
using namespace std;
int Dx = 233;
int main(){
    int ans = 0;
    set<int> s;
    int n;
    cin>>n;
    int l = 0, r =1e9;
    printf("%d 0\n", Dx);
    fflush(stdout);
    string pre;
    cin >> pre;
    for(int i=1;i<=n-1;i++){
        int mid = (l + r) >> 1;
        printf("%d %d\n", Dx, mid);
        fflush(stdout);
        string s;
        cin >> s;
        if(s!=pre)
            r = mid;
        else
        {
            l=mid;
            ans = mid;
        }
    }
    for (int i = l; i <= r;i++){
        if(!s.count(i)){
            cout << Dx-3 << " " << ans << " " << Dx+3 << " " << ans+1;
            break;
        }
    }
}