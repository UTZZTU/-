#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,res;
int main ()
{
	cin>>x;
	while(x)
	{
		if(x%2==0) x/=2;
		else
		{
			res++;
			x--;
		}
	}
	cout<<res;
	return 0;
}