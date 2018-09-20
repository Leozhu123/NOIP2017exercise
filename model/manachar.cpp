#include <iostream>
#include <cstdio>
#include <cstring>
const int maxn = 22000000;
using namespace std;
int n,hw[maxn],ans;
char a[maxn], s[maxn];
int min(int a,int b){
    return a < b ? a : b;
}
int max(int a,int b){
    return a > b ? a : b;
}
int main(){
    scanf("%s", a);
    n = strlen(a);
    s[0]=s[1]='#';
    for (int i = 0; i < n;i++){
        s[(i<<1)+2]=a[i];
        s[(i<<1) + 3] = '#';
    }
    n = n * 2 + 2;
    s[n] = 0;
    int mr=0,mid;
    for(int i=1;i<=n;i++){
        if(i<mr)
            hw[i] = min(hw[(mid << 1) - i], hw[mid] + mid - i);
        else
            hw[i] = 1;
        while(s[i + hw[i]] == s[i - hw[i]])
            ++hw[i];
        if(hw[i]+i>mr){
                mr=hw[i]+i;
                mid = i;
            }
    }
    ans = 1;
    for (int i = 0; i < n;i++)
        ans=max(ans,hw[i]);
    printf("%d" ,ans - 1);
}