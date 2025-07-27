#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,res,f[1000010],limit,xz,tt[1000010];
int main ()
{
	cin>>n>>k;
	res=n*(n+1)/2;
	for(int i=1;i<=n;i++)
	xz+=i/k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		if(i<=res%k)
		limit=ceil(res*1.0/k);
		else
		limit=res/k;
		limit-=xz;
		for(int j=n;j>=1;j--)
		{
			if(limit>0&&f[j]>(j/k*(k+1-i)))
			{
				tt[j]=j/k+1;
				limit--;
				f[j]-=(j/k+1);
			}
			else
			{
				tt[j]=j/k;
				f[j]-=(j/k);
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(j!=1)
			printf(" ");
//			if(j<=k-1)
//			{
//				printf("%d",tt[j]);
//				continue;
//			}
//			if(limit>0&&f[j]>(j/k*(k+1-i)))
//			{
//				printf("%lld",j/k+1);
//				limit--;
//				f[j]-=(j/k+1);
//			}
//			else
//			{
//				printf("%lld",j/k);
//				f[j]-=(j/k);
//			}
            printf("%d",tt[j]);
		}
		printf("\n");
	}
	return 0;
}
