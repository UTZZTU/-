#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n;
int main ()
{
	scanf("%lld",&n);
	while(n%2==0)
	{
		n/=2;
	}
	while(n%3==0)
	{
		n/=3;
	}
	if(n==1) puts("Yes");
	else puts("No");
	return 0;
}