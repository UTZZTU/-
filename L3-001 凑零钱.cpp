#include <bits/stdc++.h>
using namespace std;
int n,m,a[10010],pd,sum,ans[10010],cnt;
void dfs(int x,int sum)
{
	if(sum>m)
	return;
	if(sum==m)
	{
		pd=1;
		for(int i=0;i<cnt;i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<ans[i];
		}
		return;
	}
	for(int i=x;i<=n;i++)
	{
		ans[cnt++]=a[i];
		dfs(i+1,sum+a[i]);
		if(pd) break;
		cnt--;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<m)
	{
		cout<<"No Solution";
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	if(!pd)
	cout<<"No Solution";
	return 0;
}