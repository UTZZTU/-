#include <bits/stdc++.h>
using namespace std;
int ans1,ans2,f[110][110],n,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0};
bool check(int x,int y)
{
	if(x==1||x==n||y==1||y==n)
	return true;
	for(int i=0;i<4;i++)
	{
		int dx=dirx[i]+x,dy=diry[i]+y;
		if(f[dx][dy]>50)
		return true;
	}
	return false;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		scanf("%d",&f[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]<=50)
			{
				ans1++;
				if(check(i,j))
				ans2++;
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}