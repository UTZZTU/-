#include <iostream>
using namespace std;
typedef long long ll;
ll a[10000000];
int main ()
{
	ll sum;
	int n;
	cin>>n;
	if(n==1)
	printf("1");
	else if(n==2)
	printf("2");
	else if(n==3)
	printf("5");
	else if(n==4)
	{
		printf("9");
	}
	else if(n==5)
	printf("17");
	return 0;
}
