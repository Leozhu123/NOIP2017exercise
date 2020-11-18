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
map<string, double> weight;
void init(){
    weight["H"] = 1;
    weight["C"] = 12;
    weight["N"] = 14;
    weight["O"] = 16;
    weight["F"] = 19;
    weight["Na"] = 23;
    weight["Mg"] = 24;
    weight["Al"] = 27;
    weight["Si"] = 28;
    weight["P"] = 31;
    weight["S"] = 32;
    weight["Cl"] = 35.5;
    weight["K"] = 39;
    weight["Ca"] = 40;
    weight["Zn"] = 65;
    weight["Ag"] = 108;
    weight["I"] = 127;
    weight["Ba"] = 137;
    weight["Hf"] = 178.5;
    weight["Pt"] = 195;
    weight["Au"] = 197;
    weight["Hg"] = 201;
}
int calc(string str){
    int n = str.size() - 1;
    int pos = 0;
    int ans = 0;
    int tmp = 0;
    string name;
    name += str[pos];
    while(pos <= n){
        while(isalpha(str[pos+1])){
            pos++;
            name += str[pos];
        }
        tmp += weight[name];
    }
}
int main(){
    init();
    string str;
    cin >> str;
    cout << calc(str);

}