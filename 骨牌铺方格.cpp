#include <iostream>
using namespace std;
typedef long long ll;
ll a[55];
int main ()
{
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=50;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	int n;
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}
	return 0;
}