#include <bits/stdc++.h>
using namespace std;
int n,m,l,t;
int mp[65][1300][130];
bool vis[65][1300][130];
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct node
{
	int x,y,z;
	node(){}
	node(int x1,int y1,int z1):x(x1),y(y1),z(z1){}
};
int bfs(int x,int y,int z)
{
	queue<node> q;
	q.push((node){x,y,z});
	vis[x][y][z]=true;
	int cnt=0;
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<6;i++)
		{
			int xx=dir[i][0]+u.x;
			int yy=dir[i][1]+u.y;
			int zz=dir[i][2]+u.z;
			if(xx>=0&&xx<l&&yy>=0&&yy<n&&zz>=0&&zz<m&&!vis[xx][yy][zz]&&mp[xx][yy][zz]){
				vis[xx][yy][zz]=true;
				q.push(node(xx,yy,zz));
			}
		}
	}
	if(cnt>=t)
	return cnt;
	return 0;
}
int main ()
{
	cin>>n>>m>>l>>t;
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			scanf("%d",&mp[i][j][k]);
		}
	}
	int sum=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(!vis[i][j][k]&&mp[i][j][k]){
					sum+=bfs(i,j,k);
				}
			}
		}
	}
	printf("%d",sum);
	return 0;
}