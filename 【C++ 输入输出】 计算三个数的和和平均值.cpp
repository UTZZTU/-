#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	float a,b,c,d,e;
	cin>>a>>b>>c;
	d=a+b+c;
	e=d*1.0/3;
	cout<<fixed<<setprecision(3)<<d<<" "<<e;
	return 0;
}