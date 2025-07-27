#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(m==1)
		{
			puts("0");
			for(int i=1;i<=n;i++) puts("0");
		}
		else if(n==1)
		{
			puts("2");
			for(int i=0;i<m;i++)
			{
				printf("%d ",i);
			}
			printf("\n");
		}
		else if(m>n)
		{
			vector<vector<int> >vec(n+1);
			for(int i=0;i<=n;i++)
			{
				for(int j=-1;j<m;j++)
				{
					vec[i].push_back(j);
				}
			}
			for(int j=1;j<=n+1;j++)
			{
				for(int i=0,st=j;i<=n;i++,st++)
				{
					vec[i][j]=st%(n+1);
				}
			}
			printf("%d\n",n+1);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					printf("%d ",vec[i][j]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("%d\n",m);
			vector<vector<int> >vec(n+1);
			for(int i=0;i<=n;i++)
			{
				for(int j=-1;j<m;j++)
				{
					vec[i].push_back(j);
				}
			}
			for(int j=1;j<=m;j++)
			{
				for(int i=0,st=j;i<m;i++,st++)
				vec[i][j]=st%m;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					printf("%d ",vec[min(i,m-1)][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}