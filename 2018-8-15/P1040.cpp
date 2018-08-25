#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[100];
int dp[100][100];
vector <int> ans;
int dfs(int l,int r,vector<int> &t){
    if(l==r) {
        t.push_back(i);
        return a[l];
    }
    if(l>r) return 0;
//    if(dp[l][r]) return dp[l][r];
    int ans=0;
    vector <int> now;
    for(int i=l+1;i<=r-1;i++){
        vector<int> t1,t2;
        if(dfs(l,i-1)*dfs(i+1,r)+a[i]>ans){
            ans=dfs(l,i-1,t1)*dfs(i+1,r,t2)+a[i];
            now.clear();
            for(int j=0;j<t1.size();j++){
                now.push_back(t1[j]);
            }
            now.push_back(i);
            for(int j=0;j<t2.size();j++){
                now.push_back(t2[j]);
            }
        }
        //ans=max(ans,dfs(l,i-1)*dfs(i+1,r)+a[i]);
    }
    t=now;
    return dp[l][r]=ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> ans;
    cout<<dfs(1,n,ans)<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}    