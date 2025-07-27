#include <bits/stdc++.h>
using namespace std;
int t,n,f1[500010],f2[500010],res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f1[i]);
		}
		f2[1]=1;
		res=2;
		for(int i=1;i<=n;i++)
		{
			int t=f1[i];
			if(t==1)
			continue;
			else
			{
				f2[t]=res;
				res++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d ",f2[i]);
		}
		printf("\n");
	}
	return 0;
}