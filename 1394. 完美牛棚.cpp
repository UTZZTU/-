#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[210][210],match[210],st[210];
bool find(int x)
{
	for(int i=1;i<=m;i++)
	{
		if(!st[i]&&g[x][i])
		{
			st[i]=1;
			if(!match[i]||find(match[i]))
			{
				match[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main ()
{
	cin>>n>>m;
	for(int i=1,x,k;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>x;
			g[i][x]=1;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		memset(st,0,sizeof st);
		if(find(i)) res++;
	}
	cout<<res;
	return 0;
}