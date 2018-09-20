#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <climits>

#define MAXN 1000000
int f[MAXN],cnt[MAXN],value[MAXN],sons[MAXN][2],sub_size[MAXN],whole_size,root;                 
inline void S_Clear(int x){
    sons[x][0]=sons[x][1]=f[x]=sub_size[x]=cnt[x]=value[x]=0; 
}
inline bool get_which(int x){
    return sons[f[x]][1]==x;
}
inline void update(int x){
    if (x){  
        sub_size[x]=cnt[x];  
        if (sons[x][0]) sub_size[x]+=sub_size[sons[x][0]];  
        if (sons[x][1]) sub_size[x]+=sub_size[sons[x][1]];  
    }  
    return ;
}
inline void rotate(int x){
    int father=f[x],g_father=f[father],which_son=get_which(x);
    sons[father][which_son]=sons[x][which_son^1];
    f[sons[father][which_son]]=father;
    sons[x][which_son^1]=father;
    f[father]=x;
    f[x]=g_father;
    if(g_father){
        sons[g_father][sons[g_father][1]==father]=x;
    }
    update(father);
    update(x);
}
inline void splay(int x){
    for (int fa;fa=f[x];rotate(x))  
      if (f[fa])  
        rotate((get_which(x)==get_which(fa))?fa:x);  
    root=x;  
}
inline void insert(int x){
    if(!root){
        whole_size++;
        sons[whole_size][0]=sons[whole_size][1]=f[whole_size]=0;
        root=whole_size;
        sub_size[whole_size]=cnt[whole_size]++;
        value[whole_size]=x;
        return ;
    } 
    int now=root,fa=0;
    while(1){
        if(x==value[now]){
            cnt[now]++;
            update(now);
            update(fa);
            splay(now);
            break;
        }
        fa=now;
        now=sons[now][value[now]<x];
        if(!now){
            whole_size++;
            sons[whole_size][0]=sons[whole_size][1]=0;
            f[whole_size]=fa;
            sub_size[whole_size]=cnt[whole_size]=1;
            sons[fa][value[fa]<x]=whole_size;
            value[whole_size]=x;
            update(fa);
            splay(whole_size);
            break; 
        }
    }

}
inline int find_num(int x){ 
    int now=root;
    while(1){
        if(sons[now][0]&&x<=sub_size[sons[now][0]])
        now=sons[now][0];
        else {
            int temp=(sons[now][0]?sub_size[sons[now][0]]:0)+cnt[now];
            if(x<=temp)return value[now];
            x-=temp;
            now=sons[now][1];
        }
    }
}

inline int find_rank(int x){
      int now=root,ans=0;  
    while(1){  
        if (x<value[now])  
          now=sons[now][0];  
        else{  
            ans+=(sons[now][0]?sub_size[sons[now][0]]:0);  
            if (x==value[now]){  
                splay(now); return ans+1;  
            }  
            ans+=cnt[now];  
            now=sons[now][1];  
        }  
    }  
}
inline int find_pre(){
    int now=sons[root][0];
    while(sons[now][1])now=sons[now][1];
    return now;
}
inline int find_suffix(){
    int now=sons[root][1];
    while(sons[now][0])now=sons[now][0];
    return now;
}
inline void my_delete(int x){
    int hhh=find_rank(x);
    if (cnt[root]>1){
    cnt[root]--; 
    update(root); 
    return;
    }  
    if (!sons[root][0]&&!sons[root][1]) {
    S_Clear(root);
    root=0;
    return;
    }  
    if (!sons[root][0]){  
        int old_root=root; 
        root=sons[root][1];
        f[root]=0; 
        S_Clear(old_root); 
        return;  
    }  

    else if (!sons[root][1]){  
        int old_root=root; 
        root=sons[root][0]; 
        f[root]=0; 
        S_Clear(old_root); 
        return;  
    } 
    int left_max=find_pre(),old_root=root;  
    splay(left_max);  
    sons[root][1]=sons[old_root][1];  
    f[sons[old_root][1]]=root;  
    S_Clear(old_root);  
    update(root);  
}

inline void read(int& t) {
    int f = 0, c = getchar(); t = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (f) t = -t;
}
using namespace std;

const int maxn = 200005;
int where[maxn];
struct Qurry{
    int k,l,r,x,id;
    Qurry(){
        l = r = id  = 0;
    }
    bool operator< (const Qurry &r)const{
        if (where[l]==where[r.l]){
            if ((where[l]&1)==1) return this->r<r.r;
            else return this->r>r.r;    
        }
        return where[l] < where[r.l];
    }
};
Qurry Q[maxn];
int a[maxn];
int out[maxn];
int n=0,m=0;
int ans=0;
int Qnum=0, Cnum=0;
inline void moQueue(){
    int l = 1, r = 0;
    for (int i = 1;i<=Qnum;i++){
		while(r<Q[i].r)
            r++,insert(a[r]);
        while(r>Q[i].r)
            my_delete(a[r]),r--;
        while(l<Q[i].l) 
            my_delete(a[l]),l++;
        while(l>Q[i].l)
            l--,insert(a[l]);
        
        int x=Q[i].x;
        out[Q[i].id]=find_num(x);
    }
    for(int i=1;i<=Qnum;i++){
        printf("%d\n",out[i]);
    }
}
int main()
{
	srand(time(NULL));
    read(n);
    read(m);
    int base=sqrt(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
        where[i] = (i - 1) / base + 1;
    }
    while(m--){
    	++Qnum;
        read(Q[Qnum].l);
        read(Q[Qnum].r);
        read(Q[Qnum].x);
        Q[Qnum].id=Qnum; 
    }
    sort(Q + 1, Q + Qnum + 1);
    moQueue();
    return 0;
}
