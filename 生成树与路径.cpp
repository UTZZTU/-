#include <bits/stdc++.h>
using namespace std;
int t,n,m,cnt,w,flag;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		cnt=n-1,w=1,flag=0;
		for(int i=1;i<n;i++)
		{
			printf("%d %d %d\n",i,i+1,w);
			w++;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i-2;j>=1;j--)
			{
				if(cnt>=m)
				{
					flag=1;
					break;
				}
				printf("%d %d %d\n",i,j,w);
				w++;
				cnt++;
			}
			if(flag)
			break;
		}
	}
	return 0;
}