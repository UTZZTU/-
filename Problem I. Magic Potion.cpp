#include<bits/stdc++.h>
using namespace std;
const int N=505,M=10010;
int n1,n2,m,match[N],vis[N],n,k;
vector<int>e[N];
map<int,int>mp;
int find(int x){
	for(int i=0;i<e[x].size();i++){
		int t=e[x][i];
		if(!vis[t]){
			vis[t]=1;
			if(match[t]==0||find(match[t])){
				match[t]=x;
				mp[t]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int k,x;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
		}
		e[i].push_back(x+n);			
	}
	int res=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);	 
		if(find(i)) res++;			 
	}
	for(auto [x,y]:mp)
	{
		cout<<x-3<<" "<<y<<endl;
	}
	cout<<res<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<e[i].size();j++){
			if(mp.count(e[i][j])==0&&k>0){
				mp[e[i][j]]=i;
				res++;
				k--;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}