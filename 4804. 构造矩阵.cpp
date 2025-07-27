#include <bits/stdc++.h>
using namespace std;
int m,n,b[110][110],a[110][110],f[110][110],h[110],l[110],hh[110],ll[110];
int main ()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>b[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==0)
			h[i]=1,l[j]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(h[i]||l[j])
			f[i][j]=0;
			else
			{
				f[i][j]=1;
				hh[i]=1,ll[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j])
			{
				if(!(hh[i]||ll[j]))
				{
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<f[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}