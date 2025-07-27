#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[15][15][15][15],n;
int mq;
ll sum;
int now[4];
char s[4];
int a[2010][10];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		f[a[i][0]][a[i][1]][a[i][2]][a[i][3]]++;
		f[a[i][0]][a[i][1]][a[i][2]][10]++;
		f[a[i][0]][a[i][1]][10][a[i][3]]++;
		f[a[i][0]][10][a[i][2]][a[i][3]]++;
		f[10][a[i][1]][a[i][2]][a[i][3]]++;
		f[a[i][0]][a[i][1]][10][10]++;
		f[a[i][0]][10][a[i][2]][10]++;
		f[10][a[i][1]][a[i][2]][10]++;
		f[a[i][0]][10][10][a[i][3]]++;
		f[10][a[i][1]][10][a[i][3]]++;
		f[10][10][a[i][2]][a[i][3]]++;
		f[a[i][0]][10][10][10]++;
		f[10][10][10][a[i][3]]++;
		f[10][10][a[i][2]][10]++;
		f[10][a[i][1]][10][10]++;
		f[10][10][10][10]++;
	}
}
ll dfs(int now,int *a,int *b,int *c)
{
	ll res=0;
	if(now==4)
	{
		return f[c[0]][c[1]][c[2]][c[3]];
	}
	if(a[now]==b[now])
	{
		c[now]=a[now];
		res+=dfs(now+1,a,b,c);
	}
	else
	{
		c[now]=10;
		res+=dfs(now+1,a,b,c);
		c[now]=a[now];
		res-=dfs(now+1,a,b,c);
		c[now]=b[now];
		res-=dfs(now+1,a,b,c);
	}
	return res;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<4;j++)
		{
			a[i][j]=s[j]-'0';
		}
	}
	solve();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			now[0]=now[1]=now[2]=now[3]=0;
			sum+=dfs(0,a[i],a[j],now);
		}
	}
	printf("%lld",sum/3);
	return 0;
}
/*
6
1234
1235
1244
1233
7133
8133
*/
