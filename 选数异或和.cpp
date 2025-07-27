#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[100010],l,r,f[100010];
unordered_map<int,int> mp;
int main ()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]=i;
		f[i]=max(f[i-1],mp[a[i]^x]);
	}
	while(m--)
	{
		scanf("%d%d",&l,&r);
		if(f[r]>=l) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}