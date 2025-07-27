#include <bits/stdc++.h>
using namespace std;
int n,x[3010],y[3010],vis[3010][3010],ans,line,cnt[10000000];
int dis(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		vis[x[i]+1500][y[i]+1500]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			ans+=cnt[dis(i,j)];
			cnt[dis(i,j)]++;
			if(vis[2*x[i]-x[j]+1500][2*y[i]-y[j]+1500]) line++;
		}
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			cnt[dis(i,j)]=0;
		}
	}
	cout<<ans-line/2;
	return 0;
}