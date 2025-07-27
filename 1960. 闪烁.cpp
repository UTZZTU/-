#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b,f[1000100],res=1,num,k,loop;
int main ()
{
	scanf("%lld%lld",&n,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		num+=res*k;
		res*=2;
	}
	for(int i=1;i<=b;i++)
	{
		if(f[num])
		{
			loop=i-f[num];
			b=(b+1-f[num])%loop;
			for(int j=1;j<=b;j++)
			{
				int pos=0;
			    for(int k=1;k<=n;k++)
			    {
				    if(k==1)
				    {
					    if(num>>(n-1)&1)
					    {
						    pos+=abs((num&1)-1)*pow(2,k-1);
					    }
					    else
					    {
						    pos+=(num&1)*pow(2,k-1);
					    }
				    }
				    else
				    {
					    if(num>>(k-2)&1)
					    {
						    pos+=abs((num>>(k-1)&1)-1)*pow(2,k-1);
					    }
					    else
					    {
						    pos+=(num>>(k-1)&1)*pow(2,k-1);
					    }
				    }
			    }
			    num=pos;
			}
			break;
		}
		else
		{
			f[num]=i;
			int pos=0;
			for(int j=1;j<=n;j++)
			{
				if(j==1)
				{
					if(num>>(n-1)&1)
					{
						pos+=abs((num&1)-1)*pow(2,j-1);
					}
					else
					{
						pos+=(num&1)*pow(2,j-1);
					}
				}
				else
				{
					if(num>>(j-2)&1)
					{
						pos+=abs((num>>(j-1)&1)-1)*pow(2,j-1);
					}
					else
					{
						pos+=(num>>(j-1)&1)*pow(2,j-1);
					}
				}
			}
			num=pos;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",num>>(i-1)&1);
	}
	return 0;
}
/*
11 731657697430757
1
1
0
0
1
0
1
1
0
1
0
*/