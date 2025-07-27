#include <bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010],k,n,m,pd=-1,ans;
int main ()
{
	cin>>n>>m;
	for(int i=1,v,t;i<=n;i++)
	{
		scanf("%d %d",&v,&t);
		for(int j=1;j<=t;j++)
		{
			a[k+1]=a[k]+v;
			k++;
		}
	}
	k=0;
	for(int i=1,v,t;i<=m;i++)
	{
		scanf("%d %d",&v,&t);
		for(int j=1;j<=t;j++)
		{
			b[k+1]=b[k]+v;
			k++;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(a[i]==b[i])
		continue;
		if(a[i]>b[i])
		{
			if(pd==-1)
			pd=1;
			else if(pd==0)
			{
				ans++;
				pd=1;
			}
		}
		else if(a[i]<b[i])
		{
			if(pd==-1)
			pd=0;
			else if(pd==1)
			{
				ans++;
				pd=0;
			}
		}
	}
	cout<<ans;
	return 0;
}