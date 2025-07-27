#include <bits/stdc++.h>
using namespace std;
int f[1000010],cf[1000010],l,r,n,q,x,xw[1000010],res,maxx;
bool judge(int x)
{
	for(int i=x;i<=maxx;i+=x)
	{
		if(f[i])
		return false;
	}
	return true;
}
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		maxx=max(maxx,r);
		cf[l]++;
		cf[r+1]--;
	}
	for(int i=1;i<=1000000;i++)
	{
		res+=cf[i];
		f[i]=res;
	}
	while(q--)
	{
		scanf("%d",&x);
		if(xw[x]==1)
		printf("YES\n");
		else if(xw[x]==-1)
		printf("NO\n");
		else
		{
			if(judge(x))
			{
				xw[x]=1;
				printf("YES\n");
			}
			else
			{
				xw[x]=-1;
				printf("NO\n");
			}
		}
	}
	return 0;
}