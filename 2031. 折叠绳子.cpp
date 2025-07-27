#include <bits/stdc++.h>
using namespace std;
int node[110],n,l,pd,ans;
int main ()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	cin>>node[i];
	sort(node+1,node+1+n);
	for(int i=1;i<n;i++)
	{
		double wz=(node[i]+node[i+1])*1.0/2;
		pd=0;
		int u=i,v=i+1;
		for(u,v;u>=1&&v<=n;u--,v++)
		{
			if(wz-node[u]!=node[v]-wz)
			{
				pd=1;
				break;
			}
		}
		if(!pd)
		ans++;
	}
	for(int i=2;i<n;i++)
	{
		int wz=node[i];
		pd=0;
		int u=i-1,v=i+1;
		for(u,v;u>=1&&v<=n;u--,v++)
		{
			if(wz-node[u]!=node[v]-wz)
			{
				pd=1;
				break;
			}
		}
		if(!pd)
		ans++;
	}
	cout<<ans;
	return 0;
}