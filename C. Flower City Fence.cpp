#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],b[200010];
bool judge()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>n) return false;
		b[1]++,b[a[i]+1]--;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=b[i];
		if(res!=a[i]) return false;
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
			scanf("%d",&a[i]);
			b[i]=0;
		}
		if(judge())
		{
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}