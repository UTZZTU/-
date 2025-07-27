#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main ()
{
	cin>>a>>b;
	cout<<a*b/__gcd(a,b);
	return 0;
}