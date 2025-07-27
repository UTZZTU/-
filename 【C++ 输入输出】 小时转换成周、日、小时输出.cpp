#include <iostream>
using namespace std;
int main ()
{
	int n,a,b,c;
	cin>>n;
	a=n/7/24;
	n%=7*24;
	b=n/24;
	n%=24;
	c=n;
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}