#include <iostream>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int sum=0;
  for (int i=0;i<n;i++){
    int a;
    cin>>a;
    sum+=a/64;
    if (a%64!=0) sum++;
  }
  cout<<sum;
}
  

