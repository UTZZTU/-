#include <bits/stdc++.h>
using namespace std;
int n,m,res;
string u[1010],v[1010];
int main ()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>u[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(u[i][j]!=v[i][j])
			{
				res++;
			}
		}
	}
	if(res>n*m/2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(u[i][j]=='.') u[i][j]='X';
				else u[i][j]='.';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<u[i]<<endl;
	}
	return 0;
}