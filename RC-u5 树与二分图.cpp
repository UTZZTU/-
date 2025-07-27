#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll choose,xz1,xz2;
int pd=0;
int color[100010];
vector<int> zy;
vector<int> fy;
struct node
{
	int x,y;
	inline bool operator <(const node &u)const
	{
		return abs(color[x])+abs(color[y])<abs(color[u.x])+abs(color[u.y]);
	}
};
priority_queue<node> p;
int main ()
{
	cin>>n;
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d %d",&x,&y);
	  if(color[x]==0&&color[y]==0)
	  {
	  	if(pd==0)
	  	{
	  		color[x]=1;
	  color[y]=-1;
	  zy.push_back(x);
	  fy.push_back(y);
	   pd=1;
		 }
	  	else
	  	{
	  		p.push((node){x,y});
		  }
	  }
	  else if(color[x]==0&&color[y]==1)
	  {
	  	color[x]=-1;
	  	fy.push_back(x);
	  }
	  else if(color[x]==0&&color[y]==-1)
	  {
	  	color[x]=1;
	  	zy.push_back(x);
	  }
	  else if(color[x]==1&&color[y]==0)
	  {
	  	color[y]=-1;
	  	fy.push_back(y);
	  }
	  else if(color[x]==-1&&color[y]==0)
	  {
	  	color[y]=1;
	  	zy.push_back(y);
	  }
	}
	while(!p.empty())
	{
		node u;
		u=p.top();
		p.pop();
		int x=u.x,y=u.y;
		 if(color[x]==0&&color[y]==1)
	  {
	  	color[x]=-1;
	  	fy.push_back(x);
	  }
	  else if(color[x]==0&&color[y]==-1)
	  {
	  	color[x]=1;
	  	zy.push_back(x);
	  }
	  else if(color[x]==1&&color[y]==0)
	  {
	  	color[y]=-1;
	  	fy.push_back(y);
	  }
	  else if(color[x]==-1&&color[y]==0)
	  {
	  	color[y]=1;
	  	zy.push_back(y);
	  }
	}
	choose=n*(n-1)/2;
	xz1=zy.size()*(zy.size()-1)/2;
	xz2=fy.size()*(fy.size()-1)/2;
	choose=choose-xz1-xz2-(n-1);
	cout<<choose;
	return 0;
}
/*
7
1 2
2 3
2 4
2 5
2 6
4 7
*/