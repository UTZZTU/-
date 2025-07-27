#include <bits/stdc++.h>
using namespace std;
int w,h,n,r,x,y,vis[110][110],res;
bool check(int x,int y,int i,int j)
{
	double s=sqrt(1.0L*(x-i)*(x-i)+1.0L*(y-j)*(y-j));
	return s<=r;
}
int main ()
{
	scanf("%d%d%d%d",&w,&h,&n,&r);
	for(int k=1;k<=n;k++)
	{
		scanf("%d%d",&x,&y);
		for(int i=0;i<=w;i++)
		{
			for(int j=0;j<=h;j++)
			{
				if(check(x,y,i,j))
				{
					vis[i][j]=1;
				}
			}
		}
	}
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=h;j++)
		{
			if(vis[i][j]) res++;
		}
	}
	printf("%d",res);
	return 0;
}