#include <bits/stdc++.h>
using namespace std;
int a[20],sum,pd,n;
void dfs(int x,int y)
{
	if(pd)
	return;
	if(x>n)
	{
		if(y==0)
		pd=1;
		return;
	}
	int u=y+a[x],v=y-a[x];
	if(u%360==0)
	u=0;
	if(v%360==0)
	v=0;
	dfs(x+1,u);
	dfs(x+1,v);
}
int main ()
{
	cin>>n;
	for(int i=1,k;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%360==0)
	cout<<"YES";
	else
	{
		sort(a+1,a+1+n);
		dfs(1,0);
		if(pd)
		cout<<"YES";
		else
		cout<<"NO";
	}
	return 0;
}