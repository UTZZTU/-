#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,f[1010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		sort(f+1,f+1+n);
		int judge=1;
		for(int i=2;i<=n;i++)
		{
			if(f[i]-f[i-1]<1)
			{
				judge=0;
				break;
			}
		}
		if(judge)
		{
			for(int i=1;i<=n;i++)
			{
				printf("%d ",f[i]);
			}
			printf("\n");
		}
		else
		printf("-1\n");
	}
	return 0;
}