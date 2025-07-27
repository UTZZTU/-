#include <bits/stdc++.h>
using namespace std;
int vis[1010][1010],n,m,x,y,fx;
int main ()
{
	cin>>n>>m;
	x=1;
	y=1;
	fx=4;
	vis[1][1]=1;
	while(m--)
	{
		if(fx==4)
		{
			if(vis[x+1][y]||x+1>n)
			{
				y++;
				fx=1;
				vis[x][y]=1;
			}
			else
			{
				x++;
				vis[x][y]=1;
			}
		}
		else if(fx==1)
		{
			if(vis[x][y+1]||y+1>n)
			{
				x--;
				fx=3;
				vis[x][y]=1;
			}
			else
			{
				y++;
				vis[x][y]=1;
			}
		}
		else if(fx==2)
		{
			if(vis[x][y-1]||y-1<1)
			{
				x++;
				fx=4;
				vis[x][y]=1;
			}
			else
			{
				y--;
				vis[x][y]=1;
			}
		}
		else if(fx==3)
		{
			if(vis[x-1][y]||x-1<1)
			{
				y--;
				fx=2;
				vis[x][y]=1;
			}
			else
			{
				x--;
				vis[x][y]=1;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}