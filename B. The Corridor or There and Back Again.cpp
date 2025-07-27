#include <bits/stdc++.h>
using namespace std;
int t,n,d[110],s[110];
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(d[i]>=x) continue;
		if(x-1+(x-d[i])>=d[i]-1+s[i]) return false;
	}
	return true;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&d[i],&s[i]);
		}
		int l=1,r=1000;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}