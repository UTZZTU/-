#include <bits/stdc++.h>
using namespace std;
int st[100010][50],lg[100010],n,m,x,y;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&st[i][0]);
	}
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=lg[n];i++)
	{
		for(int j=1;j<=n-(1<<i)+1;j++)
		{
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	while(m--)
	{
		scanf("%d%d",&x,&y);
		int l=lg[y-x+1];
		printf("%d\n",max(st[x][l],st[y-(1<<l)+1][l]));
	}
	return 0;
}