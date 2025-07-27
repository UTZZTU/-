#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		int u,sum=0;
		u=ceil(n*1.0/100)*100;
		u=u-n;
		sum+=u/50;
		u%=50;
		sum+=u/20;
		u%=20;
		sum+=u/10;
		u%=10;
		sum+=u/5;
		u%=5;
		sum+=u;
		printf("%d\n",sum);
	}
	return 0;
}