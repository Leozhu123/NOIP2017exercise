#include<cstdio> 
using namespace std;
const int maxN=2000000;
int q[maxN+1][2]={0},n,m,head=0,tail=0;
int main() {
    scanf("%d%d", &n, &m);
    printf("0\n"); 
    scanf("%d", &q[tail][0]);
    tail++;
    for(int i=1; i<n; i++) {
        if(i-q[head][1]>m) head++;
        printf("%d\n", q[head][0]);
        int x;
        scanf("%d", &x);
        while(tail>head&&x<q[tail-1][0]) 
            tail--;
        q[tail][0]=x; q[tail][1]=i; 
        tail++;
    }
    return 0;
}
