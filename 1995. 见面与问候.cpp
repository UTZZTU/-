#include <bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010],k,len,ans,pd=1;
char c;
int n,m,l;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&l,&c);
		if(c=='L')
		{
			for(int j=1;j<=l;j++)
			{
				a[k+1]=a[k]-1;
				k++;
			}
		}
		else if(c=='R')
		{
			for(int j=1;j<=l;j++)
			{
				a[k+1]=a[k]+1;
				k++;
			}
		}
	}
	len=k;
	k=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %c",&l,&c);
		if(c=='L')
		{
			for(int j=1;j<=l;j++)
			{
				b[k+1]=b[k]-1;
				k++;
			}
		}
		else if(c=='R')
		{
			for(int j=1;j<=l;j++)
			{
				b[k+1]=b[k]+1;
				k++;
			}
		}
	}
	if(k>len)
	{
		for(int i=1,j=1;i<=k;i++,j++)
		{
			j=min(j,len);
			if(a[j]==b[i])
			{
				if(pd==0)
				{
					ans++;
					pd=1;
				}
			}
			else
			pd=0;
		}
	}
	else
	{
		for(int i=1,j=1;i<=len;i++,j++)
		{
			j=min(j,k);
			if(a[i]==b[j])
			{
				if(pd==0)
				{
					ans++;
					pd=1;
				}
			}
			else
			pd=0;
		}
	}
	cout<<ans;
	return 0;
}