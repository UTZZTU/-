#include <iostream>
using namespace std;
typedef long long ll;
ll a[25];
int main ()
{
	a[1]=1;
	a[2]=1;
	for(int i=3;i<25;i++)
	a[i]=a[i-1]+a[i-2];
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<n;i++)
		cout<<a[i]<<" ";
		cout<<a[n];
		cout<<endl;
	}
	return 0;
}