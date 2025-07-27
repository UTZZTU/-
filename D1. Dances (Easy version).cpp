#include <bits/stdc++.h>
using namespace std;
int t,n,m,f1[100010],f2[100010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		f1[1]=1;
		for(int i=2;i<=n;i++) scanf("%d",&f1[i]);
		for(int i=1;i<=n;i++) scanf("%d",&f2[i]);
		sort(f1+1,f1+1+n);
		sort(f2+1,f2+1+n);
		int pos=upper_bound(f2+1,f2+1+n,f1[1])-f2;
		int i=1;
		for(pos;pos<=n;pos++)
		{
			if(f2[pos]>f1[i])
			{
				i++;
			}
		}
		i--;
		printf("%d\n",n-i);
	}
	return 0;
}
