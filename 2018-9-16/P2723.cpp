#include <iostream>
#include <set>
#include <queue>
struct cmp{
    bool operator()(const int &l,const int &r){
        return l > r;
    }
};
using namespace std;
int a[200];
set<int> s;
priority_queue<int, vector<int>, cmp> q;
int main(){
    int k,n;
    cin>>k>>n;
    for (int i = 1; i <= k;i++){
        cin >> a[i];
        q.push(a[i]);
        s.insert(a[i]);
    }
    for (int i = 1;i<n;i++){
        int x=q.top();
        q.pop();
        for (int j = 1; j <= k;j++){
            if(!s.count(x * a[j])){
                s.insert(x * a[j]);
                q.push(x * a[j]);
            }
        }
    }
    cout << q.top();
    return 0;
}
