#include <bits/stdc++.h>
using namespace std;
int n,k,id,maxx=-1,f[1000010];
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&id);
		if(f[id]==0)
		f[id]=i;
		else
		{
			if(i-f[id]<=k)
			{
				maxx=max(maxx,id);
			}
			f[id]=i;
		}
	}
	printf("%d",maxx);
	return 0;
}