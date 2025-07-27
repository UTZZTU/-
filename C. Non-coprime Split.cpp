#include <bits/stdc++.h>
using namespace std;
int t,l,r,a,b,flag;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d%d",&l,&r);
		if(r-l+1>=2)
		{
			if(r&1) 
			{
				a=(r-1)/2;
				b=a;
				if(a+b>=l&&a+b<=r&&a!=1)
				printf("%d %d\n",a,b);
				else printf("-1\n");
			}
			else 
			{
				a=r/2;
				b=a;
				if(a+b>=l&&a+b<=r&&a!=1)
				printf("%d %d\n",a,b);
				else printf("-1\n");
			}
		}
		else
		{
			for(int i=2;i*i<=l;i++)
			{
				if(l%i==0)
				{
					a=l/i;
					b=l-a;
					if(a!=1) 
					{
						printf("%d %d\n",a,b);
						flag=1;
						break;
					}
				}
			}
			if(!flag)
			printf("-1\n");
		}
	}
	return 0;
}