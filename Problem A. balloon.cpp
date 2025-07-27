#include <bits/stdc++.h>
using namespace std;
int n,m,f1[100010],f2[100010],f3[100010],p;
map<int,int> mp;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f1[i]);
		f2[i]=f1[i];
	}
	sort(f2+1,f2+1+n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&f3[i]);
	}
	sort(f3+1,f3+1+m);
	for(int i=1;i<=n;i++)
	{
		int pos=upper_bound(f3+1,f3+1+m,f2[i])-f3;
		pos--;
		if(i==1) mp[f2[i]]=pos;
		else mp[f2[i]]=pos-p;
		p=pos;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",mp[f1[i]]);
	}
	return 0;
}