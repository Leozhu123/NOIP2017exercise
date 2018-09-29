#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
#define S system
int main(){
    string random,bao,best;
    int n;
    cin >> n;
    cin >> random >> bao >> best;
    for(int i=1;i<=n;i++){
        S(string(random + ">in.txt").c_str());
        S(string(bao + "<in.txt>bao.txt").c_str());
        S(string(best + "<in.txt>best.txt").c_str());
        cout << "#" << i << " :";
        if(S("fc bao.txt best.txt")!=0){
            cout << "Wrong Answer" << endl;
            break;
        }else{
            cout << "Accepted" << endl;
        }
        _sleep(1000);
    }
    return 0;
}