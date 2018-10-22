#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    for (int c1 = 0; c1 <= 3;c1++){
        for (int c2 = 0; c2<=3;c2++){
           // cout << (c1 | c2) << " "<<(c1 & c2) << endl;

          //  cout << (a == (c1 | c2)) << " " << (b==(c1 & c2)) << endl;
            if(( a == (c1 | c2) ) && ( (b) == ( c1 & c2))) {
                cout << c1 << " " << c2 << endl;
            }
        }
    }
}