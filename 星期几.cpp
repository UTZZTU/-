#include <iostream>
using namespace std;
int year=365;
bool pd(int n)
{
	if(n%4==0&&n%100!=0||n%400==0)
	return true;
	else
	return false;
}
int main ()
{
	int xq=6,ans=0;
	for(int i=1950;i<=2012;i++)
	{
		if(pd(i))
		year=366;
		else
		year=365;
		xq+=year;
		xq%=7;
		if(xq==0)
		ans++;
	}
	cout<<ans;
	return 0;
}