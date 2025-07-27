#include <iostream>
using namespace std;
typedef long long ll;
ll n,t,a[100010];
int main ()
{
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	t%=a[n];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=t)
		{
			cout<<i<<" "<<t-a[i-1];
			return 0;
		}
	}
	return 0;
}