#include <bits/stdc++.h>
using namespace std;
int t,n,k,f[200010],maxx,res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		maxx=0,res=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&f[i]);
		sort(f+1,f+1+n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				res=1;
			}
			else
			{
				if(f[i]-f[i-1]<=k) res++;
				else
				{
					maxx=max(maxx,res);
					res=1;
				}
			}
		}
		maxx=max(maxx,res);
		printf("%d\n",n-maxx);
	}
	return 0;
}