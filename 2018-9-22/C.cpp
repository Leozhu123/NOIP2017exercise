#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n,d;
long long S[200005];
long long P[200005];
int main(){
    multiset<int> s;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin >> S[i];
    }
    cin >> P[1];
    for(int i=2;i<=n;i++){
        cin >> P[i];
        s.insert(P[i]);
    }
    S[d] += P[1];
    for(int i=1;i<=n;i++){
        if(i==d) continue;
        if(*s.begin()+S[i]>S[d]){
            auto it = s.end();
            --it;
            S[i]+=(*it);
            s.erase(it);
        }else{
            auto it = s.lower_bound(S[d] - S[i]);
            if(it==s.end())
                --it;
            else if(*it>S[d]-S[i] && it!=s.begin())
                --it;
            S[i]+=*it;
            s.erase(it);
        }
    }
    long long ans = 1;
    for(int i=1;i<=n;i++){
        if(S[i]>S[d])
            ans++;
    }
    cout << ans;
}