#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> sets[100];
    int n;
    cin>>n;
    int ans = 0;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        int j=0;
        while(sets[j].count(tmp)){
            j++;
        }
        sets[j].insert(tmp);
        if(ans<j)
            ans = j;
    }
    cout << ans+1;
}