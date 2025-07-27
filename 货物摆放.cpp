#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x=2021041820210418,res,a,b,c;
int main ()
{
	for(int i=1;i<=(ll)sqrt(x);i++)
	{
		if(x%i==0)
		{
			a=i;
			ll y=x/i;
			for(int j=1;j<=(ll)sqrt(y);j++)
			{
				if(y%j==0)
				{
					b=j;
					c=y/j;
					if(a<=b&&b<=c)
					{
						if(a==b&&b==c)
						{
							res++;
						}
						else if(a==b&&b!=c||a!=b&&b==c)
						{
							res+=3;
						}
						else if(a!=b&&b!=c)
						{
							res+=6;
						}
					}
				}
			}
		}
	}
	cout<<res;
	return 0;
}