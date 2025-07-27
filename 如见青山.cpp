#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,m,n,f1[1000010],limit,f2[1000010];
int main ()
{
	scanf("%lld%lld",&t,&m);
	for(int i=1;;i++)
	{
		if(i==1)
		f1[i]=1;
		else
		f1[i]=f1[i-1]*i;
		if(f1[i]>=m)
		{
			limit=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i==1)
		f2[i]=1;
		else
		{
			f2[i]=f2[i-1]*i%m;
		}
	}
	while(t--)
	{
		scanf("%lld",&n);
		if(n>=limit)
		printf("0\n");
		else
		printf("%d\n",f2[f1[n]]);
	}
	return 0;
}