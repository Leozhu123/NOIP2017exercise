#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 30005;
int fa[maxn], dis[maxn], num[maxn];
int find(int x){
    if(x!=fa[x]){
        int k = fa[x];
        fa[x] = find(fa[x]);
        dis[x] += dis[k];
        num[x] = num[fa[x]];
    }
    return fa[x];
}
void merge(int x,int y){
    int r1 = find(x), r2 = find(y);
    if(r1!=r2){
        fa[r1] = r2;
        dis[r1] = dis[r2] + num[r2];
        num[r2]+=num[r1];
        num[r1] += num[r2];
    }
}
int query(int a,int b){
    int r1=find(a);
    int r2 = find(b);
    if(r1!=r2){
        return -1;
    }else{
        return abs(dis[a] - dis[b]) - 1;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<=maxn;i++){
    	fa[i]=i;
    	num[i]=1;
    }
    for (int i = 0; i < t;i++){
        char c;
        cin>>c;
        int a,b;
        cin >> a >> b;
        if(c=='M'){
            merge(a, b);
        }else{
            printf("%d\n", query(a, b));
        }
    }
    return 0;
}
