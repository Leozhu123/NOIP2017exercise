#include <iostream>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
int main(){
    int n;
    int now = 2000000000;
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        int c = max(a, b),d=min(a,b);
        if(c<=now){
            now=c;
        }else{
            if(d<=now){
                now = d;
            }else{
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
}