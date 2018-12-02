#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const char ccc[3]={'F','L','R'};
int main(){
    srand(time(0));
    int n=100000;
    cout << n << ' ' << 1000 << endl;
    for (int i = 1;i<=n;i++){
        cout << rand()%100 << " " << rand()%100 << endl;
    }
}