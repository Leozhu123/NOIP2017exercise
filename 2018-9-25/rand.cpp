#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include <algorithm>
#define P pair<int,int>
using namespace std;
int a[100006];
set<int> s;
int main(){
    int n = 105;
    cout << n<< endl;
    srand(time(0));
    for(int i=1;i<=n;i++){
        int x = (long long)((long long)rand() * rand()* rand()) % 1000000000;
        while(s.count(x))
            x = (long long)((long long)rand() * rand() * rand()) % 1000000000;
        cout << x << " ";
        s.insert(x);
    }
    cout << endl;
    int m = 105;
    cout << (long long)((long long)rand() * rand ()* rand()) % 1000000000 << endl;
    cout << m << endl;
    for (int i = 1; i <= m;i++){
        cout << rand() % n + 1 << " " << (long long)((long long)rand() * rand ()* rand()) % 1000000000<< endl;
    }
}