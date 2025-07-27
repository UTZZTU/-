#include <iostream>
using namespace std;
int main ()
{
	double s,a,b;
	cin>>s>>a>>b;
	double x,t;
	x=2.0*s*a/(3*a+b);
	t=(s-x)*1.0/b+x*1.0/a;
	printf("%.6f",t);
	return 0;
}