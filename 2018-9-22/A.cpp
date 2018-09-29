#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct robot{
    int x = 0, r = 0, iq = 0;
    robot(int x,int r,int iq):x(x),r(r),iq(iq){}
    bool operator<(const robot & r)const{
        return x < r.x;
    }
};
vector<robot> robots;
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x,r,q;
        cin>>x>>r>>q;
        robots.push_back(robot(x, r, q));
    }
    sort(robots.begin(), robots.end());
    long long ans = 0;
    for(int i=0;i<n;i++){
        for (int j = i - 1;j>=0;j--){
            if(robots[j].x<robots[i].x-robots[i].r)
                break;
            if(abs(robots[j].iq-robots[i].iq)<=k && robots[j].x+robots[j].r>=robots[i].x)
                ans++;
        }
        for (int j = i + 1;j<n;j++){
            if(robots[j].x>robots[i].x+robots[i].r)
                break;
            if(abs(robots[j].iq-robots[i].iq)<=k && robots[j].x-robots[j].r<=robots[i].x)
                ans++;
        }
    }
    cout << ans / 2;
}