// luogu-judger-enable-o2
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = (1 << 31) - 1;

void generate_array(long long a[], long long n, long long m, long long seed) {
    unsigned x = seed;
    for (long long i = 0; i < n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a[i] = x % m + 1;
    }
}

long long a[10000005];

queue<long long> q1, q2;

int main(){
    long long n,m,seed;
    cin>>n>>m>>seed;
    generate_array(a, n, m, seed);
    long long ans = 0;
    for (long long i = 0;i<n;i++){
//        q.push(a[i]);
        ans = max(ans, a[i]);
    }
    sort(a, a + n);
    for (long long i = 0;i<n;i++){
        q1.push(a[i]);
    }
   while(!q1.empty() || !q2.empty()){
        long long x1=INF,y1=INF,x2=INF,y2=INF,a1=INF,a2=INF;
        if(!q1.empty()){
            x1 = q1.front();
        }
        if(!q2.empty()){
            y1 = q2.front();
        }
        if(x1<y1){
            a1=x1;
            q1.pop();
          //  cout << x1<<" "<<y1 << " 1" << endl;
        }else{
            a1 = y1;
            q2.pop();
        //    cout << x1<<" "<<y1 << " 2" << endl;
        }
        if(!q1.empty()){
            x2 = q1.front();
        }
        if(!q2.empty()){
            y2 = q2.front();
        }
        if(x2<y2){
            a2=x2;
            q1.pop();
        //    cout << x2<<" "<<y2<< " 1" << endl;
        }else{
            a2 = y2;
            q2.pop();
      //      cout << x2<<" "<<y2 << " 2" << endl;
        }
        if(a2==INF)
            break;
        long long z = a1 * 2;
       // cout << a1 << " " << a2<<" "<<z<<endl;
        ans=max(z,ans);
        q2.push(z);
    }
    cout << ans;
}