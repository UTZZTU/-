#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int f[100010],n,ans,pos[100010],w[100010];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		pos[f[i]]=i;
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&w[i]);
	for(int i=1,j=1;j<=n;j++)
	{
		while(!f[i]) i++;
		if(f[i]==w[j])
		i++;
		else
		{
			f[pos[w[j]]]=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}