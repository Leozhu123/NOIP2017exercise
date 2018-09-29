#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char, char> idx;
map<char, char> idx2;
int main(){
    string a,b,c;
    cin >> a >> b >> c;
    int cnt = 0;
    for (int i = 0; i < a.size();i++){
        if(!idx.count(a[i])){
            idx[a[i]] = b[i];
            if(!idx2.count(b[i]) || idx2[b[i]]==a[i]){
                idx2[b[i]] = a[i];
            }else{
                cout<<"Failed";
                return 0;
            }
            cnt++;
        }else if(idx[a[i]]==b[i]){
            ;
        }else{
            cout<<"Failed";
            return 0;
        }
    }
    if(cnt<26){
        cout<<"Failed";
        return 0;
    }
    for (int i = 0; i < c.size();i++){
        cout << idx[c[i]];
    }
}