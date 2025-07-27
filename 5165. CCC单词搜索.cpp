#include <bits/stdc++.h>
using namespace std;
string w,s[110],v;
vector<char> vec;
int r,c,num,res,dirx[8]={-1,-1,-1,0,0,1,1,1},diry[8]={-1,0,1,-1,1,-1,0,1},vis[110][110];
bool judge()
{
	string u;
	for(int i=0;i<w.size();i++)
	{
		u+=vec[i];
	}
	return u==w;
}
bool check(int x,int y,int level)
{
	if(x>=0&&x<r&&y>=0&&y<c&&!vis[x][y]&&s[x][y]==w[level]) return true;
	return false;
}
void dfs(int x,int y,int level,int last,int pos)
{
//	cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
//	cout<<"vec:"<<vec.size()<<endl;
	if(vec.size()==w.size())
	{
		if(judge()) num++;
		return;
	}
	if(last==-1)
	{
		for(int i=0;i<8;i++)
		{
			int dx=x+dirx[i],dy=y+diry[i];
			if(check(dx,dy,level+1))
			{
				vec.push_back(s[dx][dy]);
				vis[dx][dy]=1;
				dfs(dx,dy,level+1,i,pos);
				vec.pop_back();
				vis[dx][dy]=0;
			}
		}
	}
	else
	{
		if(pos==1)
		{
			int dx=x+dirx[last],dy=y+diry[last];
			if(check(dx,dy,level+1))
			{
				vec.push_back(s[dx][dy]);
				vis[dx][dy]=1;
				dfs(dx,dy,level+1,last,pos);
				vec.pop_back();
				vis[dx][dy]=0;
			}
		}
		else
		{
			int dx=x+dirx[last],dy=y+diry[last];
			if(check(dx,dy,level+1))
			{
				vec.push_back(s[dx][dy]);
				vis[dx][dy]=1;
				dfs(dx,dy,level+1,last,pos);
				vec.pop_back();
				vis[dx][dy]=0;
			}
			for(int i=0;i<8;i++)
			{
				if(dirx[i]*dirx[last]+diry[i]*diry[last]==0)
				{
					int dx=x+dirx[i],dy=y+diry[i];
					if(check(dx,dy,level+1))
					{
						vec.push_back(s[dx][dy]);
						vis[dx][dy]=1;
						dfs(dx,dy,level+1,i,1);
						vec.pop_back();
						vis[dx][dy]=0;
					}
				}
			}
		}
	}
	return;
}
int main ()
{
	cin>>w>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>v;
			s[i]+=v;
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
		{
			if(s[i][j]==w[0])
			{
				memset(vis,0,sizeof vis);
				vec.clear();
				vec.push_back(s[i][j]);
				vis[i][j]=1;
				num=0;
				dfs(i,j,0,-1,0);
				res+=num;
//				cout<<res<<endl;
//				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<res;
	return 0;
}