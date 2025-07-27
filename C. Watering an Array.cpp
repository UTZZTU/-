#include <bits/stdc++.h>
using namespace std;
int t,n,k,d,maxx,a[2010],v[100010],cf[2010],pcnt;
int solve()
{
	int res=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		res+=cf[i];
		if(res==i) cnt++;
	}
	return cnt;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		maxx=0;
		scanf("%d%d%d",&n,&k,&d);
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld",&a[i]);
			cf[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=k;i++) scanf("%d",&v[i]);
		maxx=max(maxx,solve()+(d-1)/2);
		int i=1;
		pcnt=0;
		for(i;i<=min(d,(int)10000);i++)
		{
			int ys=(d-i-1);
			if(ys<0) break;
			pcnt++;
			pcnt%=k;
			if(pcnt==0) pcnt=k;
			cf[1]++;
			cf[v[pcnt]+1]--;
			maxx=max(maxx,solve()+ys/2);
		}
		printf("%d\n",maxx);
	}
	return 0;
}