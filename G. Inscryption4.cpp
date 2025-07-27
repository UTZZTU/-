#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,c,k,flag;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		a=1,b=0,c=0;
		flag=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			if(k==1)
			{
				a++;
			}
			else if(k==-1)
			{
				b++;
				if(a+c<=b)
				{
					flag=0;
//					break;
				}
				if(a<=b)
				{
					int temp=(b-a+2)/2;
					c-=temp;
					b-=temp;
					a+=temp;
				}
			}
			else
			{
				if(a>b+1)
				{
					b++;
					c++;
				}
				else
				{
					a++;
				}
			}
		}
		if(!flag)
		{
			puts("-1");
		}
		else
		{
			int gcd=__gcd(a,a-b);
			printf("%d %d\n",a/gcd,(a-b)/gcd);
		}
	}
	return 0;
}