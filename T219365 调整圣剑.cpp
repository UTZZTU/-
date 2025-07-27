#include <bits/stdc++.h>
using namespace std;
int n,k,q,i,j,x,y,ans=0,f[100010],minn=0x3f3f3f3f,sum,qx,hy,pd,choose[100010];
int main ()
{
	memset(choose,-1,sizeof(choose));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>q;
	for(i=1;i<=n;i++)
	{
		cin>>f[i];
		minn=min(minn,f[i]);
	}
	while(q--)
	{
		qx=0x3f3f3f3f,hy=0x3f3f3f3f;
		cin>>i>>j>>x>>y;
		for(int v=1;v<=x;v++)
		qx=min(qx,f[v]);
		for(int v=n-y+1;v<=n;v++)
		hy=min(hy,f[v]);
		if(qx<hy)
		{
			if(choose[i]==-1)
			choose[i]=qx;
			else
			choose[j]=hy;
		}
		else
		{
			if(choose[j]==-1)
			choose[j]=hy;
			else
			choose[i]=qx;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(choose[i]==-1)
		ans+=minn;
		else
		ans+=choose[i];
	}
	cout<<ans;
	return 0;
}