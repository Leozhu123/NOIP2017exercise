#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int sta[100000], pos;
map<int, bool> ma;
priority_queue<int> q;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if (x==0){
            int y;
            cin >> y;
            sta[pos++] = y;
            ma[y] = true;
            q.push(y);
        }else if (x==1){
            ma[sta[--pos]] = false;
        }else {
            int in;
            while (true){
                in = q.top();
                if (ma[in])
                    break;
                q.pop();
            }
            cout << in << endl;
        }
    }
}