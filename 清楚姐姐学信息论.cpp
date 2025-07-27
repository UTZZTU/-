#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
int main ()
{
	cin>>x>>y;
	if(x==y)
	{
		cout<<x;
		return 0;
	}
	if(y*log(x)>x*log(y))
	cout<<x;
	else if(y*log(x)==x*log(y))
	cout<<min(x,y);
	else
	cout<<y;
	return 0;
}