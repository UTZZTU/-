#include <bits/stdc++.h>
using namespace std;
int t,n,x,a[110],maxx;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		maxx=0;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			maxx=max(maxx,a[i]-a[i-1]);
		}
		maxx=max(maxx,2*(x-a[n]));
		printf("%d\n",maxx);
	}
	return 0;
}