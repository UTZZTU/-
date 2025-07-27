#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,tt;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(k<(n-1)+(m-1)||(k-(n-1)-(m-1))%2!=0)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<m;j++)
				{
					if(i==1||i==2)
					{
						if(j%2==0)
						{
							printf("R ");
						}
						else printf("B ");
					}
					else if(i==n)
					{
						if(j==m-1)
						{
							if(((n-2)+(m+1))%2==0)
							{
								printf("B ");
							}
							else printf("R ");
						}
						else
						printf("B ");
					}
					else
					{
						printf("B ");
					}
				}
				printf("\n");
			}
			for(int i=1;i<n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(j==1)
					{
						if(i==1) printf("R ");
						else printf("B ");
					}
					else if(j==2)
					{
						if(i==1)
						{
							printf("R ");
						}
						else
						{
							if(j==m-1)
							{
								if((m+i)%2==0) printf("R ");
								else printf("B ");
							}
							else
							printf("R ");
						}
					}
					else if(j==m-1)
					{
						if((m+i)%2==0) printf("R ");
						else printf("B ");
					}
					else if(j==m)
					{
						if((m-1+i)%2==0)
						{
							printf("R ");
						}
						else printf("B ");
					}
					else printf("B ");
				}
				printf("\n");
			}
		}
	}
	return 0;
}