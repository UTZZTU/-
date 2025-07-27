#include <bits/stdc++.h>
using namespace std;
int l,n,x,y,op,f[10010],p[10010],res1,res2;
int main ()
{
	scanf("%d%d",&l,&n);
	for(int i=0;i<=l;i++)
	f[i]=1;
	while(n--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op)
		{
			for(int i=x;i<=y;i++)
			{
				if(!f[i])
				{
					f[i]=1;
					p[i]=1;
				}
			}
		}
		else
		{
			for(int i=x;i<=y;i++)
			{
				if(f[i])
				{
					if(p[i]) res2++;
				}
				f[i]=p[i]=0;
			}
		}
	}
	for(int i=0;i<=l;i++)
	{
		if(f[i]&&p[i]) res1++;
	}
	printf("%d\n%d",res1,res2);
	return 0;
}