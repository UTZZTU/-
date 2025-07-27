#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inf 1e18
const int mod=1e9+7;
const int N=5050;
int n,m,ans;
int a[N],vis[N];
vector<int>e[N];

void dfs(int u,int deep,int sum){
	cout<<u<<" "<<deep<<" "<<sum<<endl;
	if(deep>min(n,(int)5)){
		ans=max(ans,sum);
		return;
	}
	for(auto it:e[u]){
		
		if(vis[it]==0){
			vis[it]=1;
			dfs(it,deep+1,sum+a[u]);
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=0;
		vis[i]=1;
		dfs(i,1,0);
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt=1;
//	cin>>tt;
	while(tt--) solve();
	return 0;
}