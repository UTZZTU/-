#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main ()
{
	int n,i,a[100010],b[100010],m=0,pd=0;
	long long k,sg=0,too1=0,too2=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--)
	{
		m=1;
		while(a[i]==a[i-1])
		{
			i--;
			m++;
		}
		if(m>=4)
		{
			sg=a[i];
			break;
		}
	}
	for(i=n;i>=1;i--)
	{
		m=1;
		while(a[i]==a[i-1])
		{
			i--;
			m++;
		}
		if(m>=2)
		{
			pd++;
			if(pd==1)
			{
				too1=a[i];
			}
			if(pd==2)
			{
				too2=a[i];
				break;
			}
		}
	}
	k=max(sg*sg,too1*too2);
	printf("%lld",k);
	return 0;
}