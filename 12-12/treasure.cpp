#include <iostream>
#include <bitset>
using namespace std;
const int INF=1<<40-1;
int n,m;
long long  dp[1<<13],G[13][13],d[13];
inline long long min(long long a,long long b){
	return a<b?a:b;
}
int dps(int S){
//	cout<<bitset<sizeof(int)*8>(S)<<endl;
	if (dp[S]!=INF) return dp[S];
	for (int to=0;to<n;to++){
		for (int from=0;from<n;from++){
		//	cout<<"from "<<from<<" "<<bitset<sizeof(int)*8>(S&(1<<from))<<endl;
		//	cout<<"to "<<to<<" "<<bitset<sizeof(int)*8>(S&(1<<to))<<endl;
		//	cout<<"G "<<G[from][to]<<endl;
			if ((S&(1<<from)!=0) && !(S&(1<<to))&& G[from][to]!=INF){
//				cout<<from<<" "<<to<<endl;
				d[to]=d[from]+1;
				dp[S]=min(dp[S],dps(S|(1<<to))+d[from]*G[from][to]);
				d[to]=INF;
			}
		}
	}
//	cout<<dp[S]<<endl;
	return dp[S];
}
void init(){
	for (int i=0;i<(1<<13);i++) dp[i]=INF;
	for (int i=0;i<13;i++) d[i]=INF;
}
long long ans=INF;
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
		G[i][j]=INF;
	}
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a-1][b-1]=min(G[a-1][b-1],c);
		G[b-1][a-1]=G[a-1][b-1];
	}
//	for (int i=0;i<n;i++){
//		for (int j=0;j<n;j++)
//		cout<<G[i][j]<<" ";
//		cout<<endl;
//}
	for (int i=0;i<n;i++){
		init();
		dp[(1<<(n))-1]=0;
		d[i]=1;
		ans=min(ans,dps((1<<i)));
	}
	cout<<ans;
}	
	
