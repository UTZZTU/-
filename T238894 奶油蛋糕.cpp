#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1010][1010],ans[1010][1010];
ll sum,n,m,x,y,t=1;
string u;
int main ()
{
	cin>>n>>m>>x>>y;
	getchar();
	cin>>u;
	f[x][y]=1;
	sum=m*(m+1)/2;
	for(int i=0;i<u.size();i++)
	{
		if(i==u.size()-1)
		continue;
		t++;
		if(u[i]=='N')
		y++;
	    else if(u[i]=='S')
		y--;
		else if(u[i]=='W')
		x--;
		else if(u[i]=='E')
		x++;
		if(f[x][y]==0)
		f[x][y]=t;
		else
		{
			ans[x][y]-=(t-f[x][y])*f[x][y];
			f[x][y]=t;
		}
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i][j]==0)
			cout<<sum;
			else
			cout<<sum+ans[i][j]-(m-f[i][j]+1)*f[i][j];
			if(i==n)
			cout<<endl;
			else
			cout<<" ";
		}
	}
	return 0;
}