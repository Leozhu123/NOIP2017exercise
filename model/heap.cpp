#include <queue>
#include <cstdio>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> > q;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if (a==1){
			int b;
			scanf("%d",&b);
			q.push(b);
		}else if (a==2){
			printf("%d\n",q.top());
		}else q.pop();
	}
}
