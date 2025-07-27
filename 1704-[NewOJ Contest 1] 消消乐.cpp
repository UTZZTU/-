#include <bits/stdc++.h>
using namespace std;
map<int,pair<int,int>> mp;
int n,f[110][110],h[110],l[110],e[10010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>f[i][j];
			mp[f[i][j]]={i,j};
		}
	}
	for(int i=1;i<=n*n;i++) cin>>e[i];
	for(int i=1;i<=n*n;i++)
	{
		int fi=mp[e[i]].first,se=mp[e[i]].second;
		h[fi]++;
		l[se]++;
		if(h[fi]==n||l[se]==n)
		{
			cout<<e[i];
			return 0;
		}
	}
	return 0;
}