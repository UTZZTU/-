#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef pair<int,int> PII;
map<PII,int> mp;
int n,m,h[N],l[N],q,t,x,y,f[N],dx[4]={0,0,-1,1},dy[4]={1,-1,0,0},res;
void rs(int x,int y,int pos)
{
	for(int i=0;i<4;i++)
	{
		int xx=dx[i]+x,yy=dy[i]+y;
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			mp[{xx,yy}]=pos;
		}
	}
}
int main ()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
		{
			if(x==1)
			{
				h[y]=i;
			}
			else
			{
				l[y]=i;
			}
		}
		else
		{
			f[i]=1;
			mp[{x,y}]=i;
			rs(x,y,i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int maxx=max(max(h[i],l[j]),mp[{i,j}]);
			if(f[maxx]) res++;
		}
	}
	printf("%d",res);
	return 0;
}