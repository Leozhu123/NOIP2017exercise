#include <iostream>
#include <cctype>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int dis[25][25];
int n;
int pe(vector<int> &p){
    int sum = 0;
    sum += dis[1][p[0]];
    for (int i = 1; i < p.size();i++){
        sum += dis[p[i - 1]][p[i]];
    }
    sum += dis[p[p.size() - 1]][1];
    return sum;
}
vector<int> choice;
int ans = 1e9;
const double delta=0.995;
void sa(){
    vector<int> nowc = choice;
    double t=2333;
	while(t>1e-15){
        vector<int> newc = nowc;
        while( ( (double)rand()/RAND_MAX ) < t/2400){
            swap(newc[rand() % (n - 1)], newc[rand() % (n - 1)]);
        }
        int newans = pe(newc);
		int DE=newans-ans;
        if(DE<0){
            choice = newc;
            nowc = newc;
            ans = newans;
		}else if(exp(-DE/t)*RAND_MAX>rand()){
            nowc = newc;
        }
		t*=delta;
	}
}
int main(){
    srand(20020713);
	cin>>n;
	for(int i=1;i<=n;i++){
        for (int j = 1; j <=n;j++){
            cin >> dis[i][j];
        }
    }
    for (int i = 2; i <= n;i++){
        choice.push_back(i);
    }
    ans = pe(choice);
    while ((double)clock() / CLOCKS_PER_SEC < 0.98)
        sa();
    cout << ans;
}