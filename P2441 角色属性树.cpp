#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int fa[N],f[N],n,k,x,y,u;
int find(int x)
{
    int tt=x;
	while(tt!=fa[tt])
	{
		tt=fa[tt];
		if(__gcd(f[tt],f[x])>1)
		return tt;
	}
	return -1;
}
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		scanf("%d",&f[i]);
	}
	n--;
	while(n--)
	{
		scanf("%d%d",&x,&y);
		fa[y]=x;
	}
	while(k--)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&u);
			printf("%d\n",find(u));
		}
		else
		{
			scanf("%d%d",&u,&y);
			f[u]=y;
		}
	}
	return 0;
}