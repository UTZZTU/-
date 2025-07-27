#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,t,a,b;
int main ()
{
	cin>>t;
	while(t--)
	{
		res=0;
		cin>>a>>b;
		while(b)
		{
			res+=(b%10)*a;
			b/=10;
		}
		cout<<res<<endl;
	}
	return 0;
}