#include <bits/stdc++.h>
using namespace std;
int t,n,q,d[510],pre;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		pre=n-1;
		for(int i=1;i<n;i++)
		{
			printf("%d %d\n",i,i+1);
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d",&d[i]);
			if(pre==d[i])
			{
				printf("-1 -1 -1\n");
			}
			else
			{
				printf("%d %d %d\n",n,pre,d[i]);
				pre=d[i];
			}
		}
		
	}
	return 0;
}