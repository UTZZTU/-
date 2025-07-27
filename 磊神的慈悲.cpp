#include <bits/stdc++.h>
using namespace std;
int pre[100010],n,m,f[100010],a,b;
int find(int x)
{
	while(x!=pre[x]) x=pre[x]=pre[pre[x]];
	return x;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	for(int i=1;i<=100000;i++)
	pre[i]=i;
	while(m--)
	{
		scanf("%d%d",&a,&b);
		pre[a]=b;
	}
	for(int i=1;i<=100000;i++)
	{
		pre[i]=find(i);
	}
	for(int i=1;i<=n;i++)
	cout<<pre[f[i]]<<" ";
	return 0;
}