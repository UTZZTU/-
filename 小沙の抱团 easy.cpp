#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res;
int main ()
{
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	while(n!=2)
	{
		if(n&1)
		{
			res++;
			n=(n+1)/2;
		}
		else
		{
			res++;
			n=ceil((n+1)*1.0/2);
		}
	}
	cout<<res;
	return 0;
}