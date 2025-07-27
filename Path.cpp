#include <bits/stdc++.h>
using namespace std;
string a[55];
int n,ans1,ans2,vis[55][55];
int main ()
{
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	getline(cin,a[i]);
	for(int i=0;i<n;i++)
	{
		int js=0,qd;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='P'&&!vis[i][j])
			{
				if(!js)
				qd=j;
				js++;
			}
			if(a[i][j]=='N'||vis[i][j])
			{
				if(js>=2)
				{
					for(int k=qd;k<j;k++)
					vis[i][k]=1;
					ans1++;
				}
				js=0;
				qd=0;
			}
		}
		if(js>=2)
				{
					for(int k=qd;k<n;k++)
					vis[i][k]=1;
					ans1++;
				}
	}
	for(int i=0;i<n;i++)
	{
		int js=0,qd;
		for(int j=0;j<n;j++)
		{
			if(a[j][i]=='P'&&!vis[j][i])
			{
				if(!js)
				qd=j;
				js++;
			}
			if(a[j][i]=='N'||vis[j][i])
			{
				if(js>=1)
				{
					for(int k=qd;k<j;k++)
					vis[k][i]=1;
					ans1++;
				}
				js=0;
                qd=0;
			}
		}
		if(js>=1)
				{
					for(int k=qd;k<n;k++)
					vis[k][i]=1;
					ans1++;
				}
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		int js=0,qd;
		for(int j=0;j<n;j++)
		{
			if(a[j][i]=='P'&&!vis[j][i])
			{
				if(!js)
				qd=j;
				js++;
			}
			if(a[j][i]=='N'||vis[j][i])
			{
				if(js>=2)
				{
					for(int k=qd;k<j;k++)
					vis[k][i]=1;
					ans2++;
				}
				js=0;
				qd=0;
			}
		}
		if(js>=2)
				{
					for(int k=qd;k<n;k++)
					vis[k][i]=1;
					ans2++;
				}
	}
	for(int i=0;i<n;i++)
	{
		int js=0,qd;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='P'&&!vis[i][j])
			{
				if(!js)
				qd=j;
				js++;
			}
			if(a[i][j]=='N'||vis[i][j])
			{
				if(js>=1)
				{
					for(int k=qd;k<j;k++)
					vis[i][k]=1;
					ans2++;
				}
				js=0;
                qd=0;
			}
		}
		if(js>=1)
				{
					for(int k=qd;k<n;k++)
					vis[i][k]=1;
					ans2++;
				}
	}
	cout<<min(ans1,ans2);
	return 0;
}