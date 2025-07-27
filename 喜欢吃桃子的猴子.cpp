#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	int n;
	ll sum=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum=(sum+1)*2;
	}
	cout<<sum;
	return 0;
}