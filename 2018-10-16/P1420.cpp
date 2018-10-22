#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin>>n;
    int now=0;
    int ans=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==now){
            cnt++;
            now=x+1;
        }else{
            now=x+1;
            ans=max(ans,cnt);
	    cnt=1;
        }
    }
    cout<<ans<<endl;
}
