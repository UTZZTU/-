#include <iostream>
#include <cmath>
using namespace std;
template<typename T>
T power(T x,int y)
{
	return pow(x,y);
}
int main ()
{
	int a,b,n;
	double c,d;
	cin>>a>>n;
	b=power(a,n);
	cin>>c>>n;
	d=power(c,n);
	cout<<b<<endl;
	cout<<d<<endl;
	return 0;
}