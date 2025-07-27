#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	int n;
	cin>>n;
	if(n==1)
	cout<<1;
	else if(n==2)
	cout<<2;
	else
	{
		ll a[20];
		a[1]=1;
		a[2]=2;
		for(int i=3;i<=n;i++)
		{
			a[i]=a[i-1]*(4*i-2)/(i+1);
		}
		cout<<a[n];
	}
	return 0;
}
//卡特兰数