#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define LL unsigned long long
using namespace std;
template <typename T>
inline void read(T &t)
{
    int f = 0, c = getchar();
    t = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        t = t * 10 + c - 48, c = getchar();
    if (f)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args)
{
    read(t);
    read(args...);
}
const LL P=1e9+7;
namespace Mker
{
    unsigned long long SA,SB,SC;
    void init(){scanf("%llu%llu%llu",&SA,&SB,&SC);}
    unsigned long long rand()
    {
        SA^=SA<<32,SA^=SA>>13,SA^=SA<<1;
        unsigned long long t=SA;
        SA=SB,SB=SC,SC^=t^SA;return SC;
    }
}
struct Mat{
    int n=2;
    LL a[3][3];
    Mat(){
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
    			a[i][j]=0;
	}
    Mat operator*(const Mat &b) const{
        Mat res;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                res.a[i][j]=0;
        for(int i=1;i<=n;i++)
            for(int k=1;k<=n;k++)
                for(int j=1;j<=n;j++)
                    res.a[i][j]+=a[i][k]*b.a[k][j],res.a[i][j]%=P;
        return res;
    }
};
Mat pow(Mat x,LL y){
    Mat ans;
    ans.a[1][1]=ans.a[2][2]=1;
    while(y)
    {
        if(y&1)
            ans=ans*x; 
        x=x*x;
        y>>=1;
    }
    return ans;
}
int T;
LL d[50000005];
int main(){
    read(T);
    Mker::init();
    LL ans=0;
    for(int i=1;i<=T;i++){
        d[i]=Mker::rand();
	}
	sort(d+1,d+T+1);
	Mat now;
	now.a[1][1]=now.a[2][2]=1;
	for(int i=1;i<=T;i++){
		Mat mat;
        mat.a[1][1]=233;
        mat.a[1][2]=666;
        mat.a[2][1]=1;
        mat.a[2][2]=0;
        mat=pow(mat,d[i]-d[i-1]);
        now=mat*now;
        ans^=now.a[2][1];
	}	
    cout<<ans;
}
