#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	ll a,b,n,z,ts=0,i;
	cin>>a>>b>>n;
	z=5*a+2*b;
	ts+=(n/z)*7;
	n%=z;
	for(i=1;i<=7;i++)
	{
		if(i<=5)
		n-=a;
		else 
		n-=b;
		ts++;
		if(n<=0)
		break;
	}
	printf("%lld",ts);
	return 0;
}
