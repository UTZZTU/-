#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,cnt,pos;
};
string s[50];
int res,n=50;
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n&&s[x][y]!='*') return true;
	return false;
}
void bfs()
{
	queue<node> q;
	q.push({0,0,0,-1});
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		if(u.x==n-1&&u.y==n-1)
		{
//			cout<<u.cnt<<endl;
			if(u.cnt<=3)
			res++;
			continue;
		}
		if(u.pos==-1)
		{
			int xx=u.x,yy=u.y+1;
			if(check(xx,yy))
			{
				q.push({xx,yy,0,0});
			}
			xx=u.x+1,yy=u.y;
			if(check(xx,yy))
			{
				q.push({xx,yy,0,1});
			}
		}
		else
		{
			int xx=u.x,yy=u.y+1;
			if(check(xx,yy))
			{
				if(u.pos!=0)
				{
					if(u.cnt+1<=3)
					{
						q.push({xx,yy,u.cnt+1,0});
					}
				}
				else
				q.push({xx,yy,u.cnt,0});
			}
			xx=u.x+1,yy=u.y;
			if(check(xx,yy))
			{
				if(u.pos!=1)
				{
					if(u.cnt+1<=3)
					{
						q.push({xx,yy,u.cnt+1,1});
					}
				}
				else
				q.push({xx,yy,u.cnt,1});
			}
		}
	}
}
int main ()
{
//	for(int i=0;i<n;i++)
//	{
//		cin>>s[i];
//	}
//	bfs();
//	cout<<res;
	cout<<647;
	return 0;
}