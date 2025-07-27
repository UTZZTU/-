#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int g[N][N];
int ma[N*N];
int T,s,n;
bool check(int num)
{
	int cnt=ma[num];
	int x=cnt/s+(cnt%s==0?0:1),y=cnt%s==0?s:cnt%s;
	for(int i=0;i<4;i++)
	{
		int ux=dx[i]+x,uy=dy[i]+y;
		if(ux>=1&&ux<=s&&uy>=1&&uy<=s&&g[ux][uy]==num+1)
		return true;
	}
	return false;
}
int main ()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
		{
			for(int k=1;k<=s;k++)
			{
				scanf("%d",&g[j][k]);
				ma[g[j][k]]=(j-1)*s+k;
			}
		}
		int ans=0,pos;
		for(int j=1;j<=s*s;j++)
		{
			int k=j;
			while(check(k)) k++;
			if(ans<k-j+1)
			{
				ans=k-j+1;
				pos=j;
			}
			j=k;
		}
		printf("Case #%d: %d %d\n",i,pos,ans);
	}
	return 0;
}