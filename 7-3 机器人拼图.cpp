#include <bits/stdc++.h>
using namespace std;
int a[110][110];
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		string u;
		cin>>u;
		int hx=1,zx=1,zy,sx;
		for(int j=0;j<u.size()-1;j++)
		{
		    sx=0,zy=0;
			if(u[j]=='1')zy=1;
			else if(u[j]=='2')sx=1;
			else if(u[j]=='3')zy=-1;
			else sx=-1;
			if(zy+hx<1||zy+hx>m||sx+zx<1||sx+zx>n)
		continue;
		hx+=zy;
		zx+=sx;
		}
		if(!a[zx][hx])
		a[zx][hx]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=1)
			cout<<" ";
			cout<<a[i][j];
		}
		if(i!=n)
		cout<<endl;
	}
	return 0;
}