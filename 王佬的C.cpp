#include<bits/stdc++.h>
#define ll long long
#define close ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
char mp[1005][1005];
int d1[1005][1005],d2[1005][1005];
bool vis1[1005][1005],conf[1005][1005],vis2[1005][1005];
int n,m,r1,r2,px,py,mx,my,flag=0;
int dir[4][2]={0,1,0,-1,-1,0,1,0};
struct node{
	int x,y,dis;
};
void b1();
void b2();
int main()
{
	cin>>n>>m>>r1>>r2;
	for(int i=1;i<=n;i++)
		cin>>mp[i]+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='P')
				px=i,py=j;
			else if(mp[i][j]=='M')
				mx=i,my=j;
		}
	}
	b1();
	b2();
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(conf[i][j]&&d1[i][j]&&d2[i][j]){
				ans=min(ans,d1[i][j]+d2[i][j]);
			}
		}
	if(ans==0x3f3f3f3f)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
void b1(){
	queue<node>q;
	q.push({mx,my,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(vis1[u.x][u.y])
			continue;
		vis1[u.x][u.y]=true;
		d1[u.x][u.y]=u.dis;
		if(abs(u.x-px)+abs(u.y-py)<=r1&&abs(u.x-mx)+abs(u.y-my)<=r2){
			conf[u.x][u.y]=true;
		}
		for(int i=0;i<4;i++){
			int nxx=u.x+dir[i][0],nxy=u.y+dir[i][1];
			if(nxx>=1&&nxx<=n&&nxy>=1&&nxy<=m&&mp[nxx][nxy]!='*')
				q.push({nxx,nxy,u.dis+1});
		}
	}
}
void b2(){
	queue<node>q;
	q.push({px,py,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(vis2[u.x][u.y])
			continue;
		vis2[u.x][u.y]=true;
		d2[u.x][u.y]=u.dis;
		for(int i=0;i<4;i++){
			int nxx=u.x+dir[i][0],nxy=u.y+dir[i][1];
			if(nxx>=1&&nxx<=n&&nxy>=1&&nxy<=m&&mp[nxx][nxy]!='*')
				q.push({nxx,nxy,u.dis+1});
		}
	}
}
