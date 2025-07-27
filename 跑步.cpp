#include <bits/stdc++.h>
using namespace std;
int n,p,v,maxx,cnt,pv,fa[100010],sp[100010];

int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p,&v);
		mp1[p]++;
		if(mp2[p]==0)
		{
			mp2[p]=v;
		}
		else
		{
			mp2[p]=min(mp2[p],v);
		}
	}
	
	return 0;
}