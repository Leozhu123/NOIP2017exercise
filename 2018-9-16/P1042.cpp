#include <iostream>
#include <vector>
using namespace std;
vector<char>  rec;
int main(){
    char ch;
    cin>>ch;
    while(ch!='E'){
        rec.push_back(ch);
        cin >> ch;
    }
    int a = 0, b = 0;
    for (int i = 0; i < rec.size();i++){
        if(rec[i]=='W')
            a++;
        else b++;
        if((a>=11 || b>=11) && (abs(a-b)>=2)){
            cout << a << ':' << b << endl;
            a = b = 0;
        }
    }
    cout << a << ':' << b << endl;
    cout<<endl;
    a = b = 0;
    for (int i = 0; i < rec.size();i++){
        if(rec[i]=='W')
            a++;
        else b++;
        if((a>=21 || b>=21) && (abs(a-b)>=2)){
            cout << a << ':' << b << endl;
            a = b = 0;
        }
    }
    cout << a << ':' << b << endl;
}