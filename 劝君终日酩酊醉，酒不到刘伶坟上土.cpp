#include <iostream>
using namespace std;
typedef long long ll;
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,k,a,b,o;
		ll sum=0;
		cin>>n>>m>>k;
		a=max(n,m);
		b=min(n,m);
		o=k/2;
		if(k>=2*min(n,m)-1)
		{
			sum=n*m;
		}
		else
		{
			sum+=o*(a+a-o+1)/2+o*(b-1+b-o)/2;
			if(k&1)
			sum+=a-o;
		}
		cout<<sum<<endl;
	}
	return 0;
}