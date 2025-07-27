#include <bits/stdc++.h>
using namespace std;
int cnt[1000100],pos[1000100],a[1000100],n;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=1000000;i++)
	{
		for(int j=i;j<=1000000;j+=i)
		{
			pos[j]+=cnt[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",pos[a[i]]-1);
	}
	return 0;
}