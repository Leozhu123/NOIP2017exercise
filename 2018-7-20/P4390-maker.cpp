#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;
struct command{
    long long ran, q, x1, y1, x2, y2,add;
};
bool cmp(command a,command b){
    return a.ran < b.ran;
}
command comds[200000];
int main(){
    srand(time(NULL));
    long long W=2000000;
    for(long long i=1;i<=160000;i++){
        comds[i].ran=rand();
        comds[i].q = 1;
        comds[i].x1 = (rand()*1926)%W;
        comds[i].y1 = (rand()*1926)%W;
        comds[i].add = (rand())%10000;
    }
    for(long long i=160001;i<=170000;i++){
        comds[i].ran=rand();
        comds[i].q = 2;
        comds[i].x1 = (rand()*1926)%W;
        comds[i].y1 = (rand()*1926)%W;
        comds[i].x2 = (rand()*1926)%W;
        comds[i].y2 = (rand()*1926)%W;
        if(comds[i].x1>comds[i].x2) swap(comds[i].x1,comds[i].x2);
        if(comds[i].y1>comds[i].y2) swap(comds[i].y1,comds[i].y2);
    }
    sort(comds+1,comds+170001,cmp);
    freopen("P4390.in","w",stdout);
    printf("0 %lld\n",W);
    for (long long i = 1;i<=170000;i++){
        if(comds[i].q==1){
            printf("1 %lld %lld %lld\n",comds[i].x1,comds[i].y1,comds[i].add); 
        }else{
            printf("2 %lld %lld %lld %lld\n",comds[i].x1,comds[i].y1,comds[i].x2,comds[i].y2); 
        }
    }
    cout << 3;

}