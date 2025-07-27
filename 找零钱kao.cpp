#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main ()
{
	ll n,sum;
	while(cin>>n)
	{
		sum=0;
		ll qs,cs;
		qs=ceil(n*1.0/100)*100;
		cs=qs-n;
		if(cs>=50)
		{
			sum+=cs/50;
			cs%=50;
		}
		if(cs>=20)
		{
			sum+=cs/20;
			cs%=20;
		}
		if(cs>=10)
		{
			sum+=cs/10;
			cs%=10;
		}
		if(cs>=5)
		{
			sum+=cs/5;
			cs%=5;
		}
		sum+=cs;
		printf("%lld\n",sum);
	}
	return 0;
}