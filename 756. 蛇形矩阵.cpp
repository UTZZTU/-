#include <bits/stdc++.h>
using namespace std;
int n,m,pos=1,f[110][110],x,y;
int main ()
{
	scanf("%d %d",&n,&m);
	x=1,y=1;
	while(pos<=n*m)
	{
		while(pos<=n*m&&!f[x][y]&&x>=1&&x<=n&&y>=1&&y<=m)
		{
			f[x][y]=pos;
			pos++;
			y++;
		}
		y--,x++;
		while(pos<=n*m&&!f[x][y]&&x>=1&&x<=n&&y>=1&&y<=m)
		{
			f[x][y]=pos;
			pos++;
			x++;
		}
		x--,y--;
		while(pos<=n*m&&!f[x][y]&&x>=1&&x<=n&&y>=1&&y<=m)
		{
			f[x][y]=pos;
			pos++;
			y--;
		}
		y++,x--;
		while(pos<=n*m&&!f[x][y]&&x>=1&&x<=n&&y>=1&&y<=m)
		{
			f[x][y]=pos;
			pos++;
			x--;
		}
		x++,y++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=1)
			cout<<" ";
			cout<<f[i][j];
		}
		cout<<endl;
	}
	return 0;
}