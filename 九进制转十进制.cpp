#include <iostream>
using namespace std;
int main ()
{
	int n,t;
	cin>>n;
	while(n!=0)
	{
		t=n%9;
		printf("%d\n",t);
		n/=9;
	}
	//1478
	return 0;
}
