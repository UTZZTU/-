#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
	long long a,b,t,cs=0;
	scanf("%lld %lld",&a,&b);
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(a!=0&&b!=0)
	{
		cs+=a/b;
		a=a%b;
		t=a;
		a=b;
		b=t;
	}
	printf("%lld",cs);
	return 0;
}