#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,h,r,f[10010],res;
signed main ()
{
	while(~scanf("%d%d%d",&l,&h,&r))
	{
		for(int i=l;i<r;i++) f[i]=max(f[i],h);
	}
//	int i=1;
//	while(f[i]==0) i++;
//	printf("%d %d ",i,f[i]);
//	i++;
	for(int i=1;i<=10000;i++)
	{
		if(f[i]!=f[i-1])
		{
			printf("%d %d ",i,f[i]);
		}
// 		else if(f[i]<f[i-1])
// 		{
// 			printf("%d %d ",i,f[i]);
// 		}
// 		if(f[i]!=res)
// 		{
// 			printf("%d %d ",i,f[i]);
// 			res=f[i];
// 		}
	}
	return 0;
}