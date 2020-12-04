//by ciwomuli
//enter ICPC WF 2020
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
const int maxn = 1e5 + 5;
vector<int> G[maxn];
void add_edge_directed(int a,int b){
    G[a].push_back(b);
}
void add_edge(int a,int b){
    G[a].push_back(b);
    G[b].push_back(a);
}

void print_pos(int a){
    for (int i = 0; i < G[a].size();i++){
        cout << G[a][i] << " ";
    }
}

int main(){

}