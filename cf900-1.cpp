#include <bits/stdc++.h>
using namespace std;
int t,n,k,f;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f);
			mp[f]++;
		}
		if(mp[k]) puts("YES");
		else puts("NO");
	}
	return 0;
}