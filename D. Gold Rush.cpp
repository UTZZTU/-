#include <bits/stdc++.h>
using namespace std;
int t,n,m,flag;
void dfs(int x)
{
	if(flag) return;
	if(x==m)
	{
		flag=1;
		return;
	}
	if(x%3==0)
	{
		dfs(x/3);
		dfs(x/3*2);
	}
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		flag=0;
		dfs(n);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}