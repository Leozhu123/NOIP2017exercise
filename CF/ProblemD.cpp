#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct s{
    string str;
    int times = 0;
    s(string s,int t){{
        times=t;
        str = s;
    }}
};
struct q{
    string str;
    vector<int> vk;
    q(string str){
        this->str = str;
    }
};
vector<string> vs;
vector<s> vss;
vector<pair<string, int>> vq;
vector<q> vqq;
int value[20];
int main(){
    int n,m,q;
    for(int i=1;i<=n;i++){
        cin >> value[i];
    }
    for(int i=1;i<=m;i++){
        string s;
        cin >> s;
        vs.push_back(move(s));
    }
    sort(vs.begin(), vs.end());
    int times = 0;
    string last = vs.begin();
    for (auto it = vs.begin();it!=vs.end();it++){
        if(*it==last){
            times++;
        }else{
            vss.push(s(*it, times));
            last = *it;
            times = 1;
        }
    }
    for(int i=1;i<=q;i++){
        string str;
        int k;
        cin>>str>>k;
        vq.push(pair<string, int>(move(str), k));
    }
    sort(vq.begin(), vq.end());
    for (auto it = vq.begin();it!=vq.end();it++){
        if(*it==last){
            (vqq.end() - 1)->vk.push_back(*it.second);
        }else{
            vqq.push(q(it->first));
            (vqq.end() - 1)->vk.push_back(*it.second);
        }
    }
}