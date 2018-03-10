#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

const int NP = 0, MP = 1, ZP = 2, FP = 3, LFP = 4; //NP未表身份，LFP为类反猪
const int P = 1, K = 2, D = 3, F = 4, N = 5, W = 6, J = 7, Z = 8;
queue<int> piles; //牌堆
struct Pig
{
    queue<int> cards;
    bool has_z, dead;
    int rstatus, mstatus, blood; //rstatus真实身份,mstatus主猪眼中身份
    Pig()
    {
        rstatus = mstatus = NP;
        blood = 4;
        has_z = false;
        dead = false;
    }
};
Pig pigs[20];
map<string, int> str2int;
int n = 0, m = 0, now_p = 0;
inline void init();
inline int next_pig(int x);
int main()
{
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        pigs[i].rstatus = str2int[str];
        if (i == 0)
            pigs[i].mstatus = MP;
        for (int j = 0; j < 4; j++)
        {
            cin >> str;
            pigs[i].cards.push(str2int[str]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        piles.push(str2int[str]);
    }
    //以上为读入部分
    while (true)
    {

    }
}
inline void init()
{
    str2int["NP"] = NP;
    str2int["MP"] = MP;
    str2int["ZP"] = ZP;
    str2int["FP"] = FP;
    str2int["LFP"] = LFP;
    str2int["P"] = P;
    str2int["K"] = K;
    str2int["D"] = D;
    str2int["F"] = F;
    str2int["N"] = N;
    str2int["W"] = W;
    str2int["J"] = J;
    str2int["Z"] = Z;
}
inline int next_pig(int x)
{
    int t = x + 1;
    while (pigs[t].dead)
    {
        t++;
        if (t == n)
            t = 0;
    }
    return t;
}