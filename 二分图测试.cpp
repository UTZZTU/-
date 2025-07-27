#include <bits/stdc++.h>
using namespace std;
int n,choose;
int G[10001][10001];
int color[100010];
bool judge(int x,int y)
{
	if(color[x]&&color[y]&&color[x]+color[y]==0)
	return true;
	else 
	return false;
}
int main ()
{
	cin>>n;
	for(int i=1,x,y;i<n;i++)
	{
	  cin>>x>>y;
	  G[x][y]=1;
	  G[y][x]=1;
	  if(color[x]==0&&color[y]==0)
	  {
	  	color[x]=1;
	  color[y]=-1;
	  }
	  if(color[x]==0&&color[y]==1)
	  {
	  	color[x]=-1;
	  }
	  if(color[x]==0&&color[y]==-1)
	  {
	  	color[x]=1;
	  }
	  if(color[x]==1&&color[y]==0)
	  {
	  	color[y]=-1;
	  }
	  if(color[x]==-1&&color[y]==0)
	  {
	  	color[y]=1;
	  }
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(G[i][j])
			continue;
			cout<<"tgl"<<i<<" "<<j<<endl;
				if(judge(i,j))
				{
					choose++;
				}
		}
	}
	cout<<choose;
	return 0;
}