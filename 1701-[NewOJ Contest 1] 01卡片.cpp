#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
void add(ll x)
{
	while(x)
	{
		if(x&1) b++;
		else a++;
		x>>=1;
	}
}
int main ()
{
//	for(ll i=1;i<=20222022;i++)
//	{
//		add(i);
//	}
//	cout<<a<<" "<<b;
	cout<<"230401142 241595002";
	return 0;
}