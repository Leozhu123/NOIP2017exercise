#include<cstdio>
using namespace std;
long long n,k,p[2000002],c[2000002],ans;
int cnt;
int main(){
    scanf("%lld%lld",&n,&k);
    cnt=0;
    for(long long i=2;i*i<=k;++i)
    if(k%i==0){
        p[++cnt]=i;
        c[cnt]=0;
        while(k%i==0){
            ++c[cnt];
            k/=i;
        }
    }
    if(k>1){
        p[++cnt]=k;
        c[cnt]=1;
    }
    ans=2e18;
    for(int i=1;i<=cnt;++i){
        long long t=0,now=n;
        while(now)t+=now/=p[i];
        t/=c[i];
        if(t<ans)ans=t;
    }
    printf("%lld\n",ans);
    return 0;
}