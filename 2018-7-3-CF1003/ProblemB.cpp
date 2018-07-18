#include <iostream>
using namespace std;
int main(){
    int a[2],x,now;
    cin>>a[0]>>a[1]>>x;
    if(a[0]>a[1]){
        if(x%2==0){
            now = 0;
        }else {
            now = 1;
        }
        for (int i=0;i<x;i++){
            cout<<now;
            a[now]--;
            now ^= 1;
        }
        for (int i=0;i<a[1];i++){
            cout << 1;
        }   
        for (int i=0;i<a[0];i++){
            cout << 0;
        }
    }else{
        if(x%2==0){
            now = 1;
        }else {
            now = 0;
        }
        for (int i=0;i<x;i++){
            cout<<now;
            a[now]--;
            now ^= 1;
        }
        for (int i=0;i<a[0];i++){
            cout << 0;
        }   
        for (int i=0;i<a[1];i++){
            cout << 1;
        }
    }
}