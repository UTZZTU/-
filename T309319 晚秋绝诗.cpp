#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,z;
double c;
int main ()
{
	cin>>x>>z;
	cin>>c;
	y=x-2*z;
	cout<<ceil(y/c);
	return 0;
}