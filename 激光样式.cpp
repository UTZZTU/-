#include <iostream>
using namespace std;
int a[35][3];
int main ()
{
	a[0][0]=1;
	for(int i=1;i<=30;i++)
	{
		a[i][0]=a[i-1][0]+a[i-1][1];
		a[i][1]=a[i-1][0];
	}
	cout<<a[30][0]+a[30][1];
	return 0;
}