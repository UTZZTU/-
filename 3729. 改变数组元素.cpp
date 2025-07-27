#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		unordered_map<int,int> mp;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i])
			{
				mp[max(1,i-a[i]+1)]++;
				mp[i+1]--;
			}
		}
		int res=0;
		for(int i=1;i<=n;i++)
		{
			res+=mp[i];
			if(res)
			printf("1 ");
			else
			printf("0 ");
		}
		printf("\n");
	}
	return 0;
}