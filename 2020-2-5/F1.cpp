//by ciwomuli
//AK JSOI 2019
//I love wyt
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
#include <string>
#include <sstream>
#define LL long long
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
int n,m,k;
int a[55][20005];
int dp[55][20005];
int lch[100005],rch[100005],d[100005];
int tot = 1;
void build(int &curr,int l,int r){
    curr = tot++;
    if(l == r)
        return;
    int mid = (l+r)>>1;
    build(lch[curr],l,mid);
    build(rch[curr], mid + 1, r);
}
void modify(int curr,int pos,int l,int r,int x){
    if(l == r){
        d[curr] = x;
        return;
    }
    int mid = (l+r)>>1;
    if(pos <= mid) modify(lch[curr],pos,l,mid,x);
    else modify(rch[curr],pos,mid+1,r,x);
    d[curr] = max(d[lch[curr]], d[rch[curr]]);
}
int qurry(int curr,int l,int r,int L,int R){
   if(L <= l && r <= R){
       return d[curr];
   } 
   int mid = (l+r)>>1;
   int ans = 0;
   if(L <= mid)  ans = max(ans,qurry(lch[curr],l,mid,L,R));
   if(R >= mid+1)
       ans = max(ans, qurry(rch[curr], mid + 1, r, L, R));
   return ans;
}
int main(){
    read(n,m,k);
    int root;
    build(root, 1, m);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            read(a[i][j]);
        }
    }
    for (int j = 1; j <= m - k + 1;j++){
        int sum = 0;
        for (int ii = j; ii <= j + k - 1;ii++){
            sum += a[1][ii] + a[2][ii];
        }
        dp[1][j] = sum;
        modify(root, j, 1, m, dp[1][j]);
    }
    for (int i = 2;i<=n;i++){
        for (int j = 1;j<=m-k + 1;j++){
            int sum = 0;
            for (int ii = j; ii <= j + k - 1;ii++){
                sum += a[i][ii] + a[i+1][ii];
            }
            for (int jj = max(1, j - k + 1); jj <= j;jj++){
                int tmp = 0;
                for (int kk = j; kk <= jj + k - 1;kk++)
                    tmp += a[i][kk];
                dp[i][j] = max(dp[i][j], dp[i - 1][jj] + sum - tmp);
            }
            for (int jj = j; jj <= min(m,j+k - 1);jj++){
                int tmp = 0;
                for (int kk = jj; kk <= j + k - 1;kk++)
                    tmp += a[i][kk];
                dp[i][j] = max(dp[i][j], dp[i - 1][jj] + sum - tmp);
            }
            if(j-k >=1) dp[i][j] = max(dp[i][j], sum + qurry(root, 1, m, 1, j-k));
            if(j+k<=m)dp[i][j] = max(dp[i][j], sum + qurry(root, 1, m, j+k, m));
        }
        for (int j = 1;j<=m;j++){
            modify(root, j, 1, m, dp[i][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}