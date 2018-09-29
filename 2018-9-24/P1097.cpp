#include <iostream>
#include <map>
using namespace std;
#define LL long long
map<LL,LL> idx;
int main(){
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++){
        LL x;
        cin>>x;
        idx[x]++;
    }
    for (auto it = idx.begin(); it != idx.end();it++){
        cout << it->first << " " << it->second << endl;
    }
}