#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
int main ()
{
	cin>>a>>b>>c>>d;
	cout<<max(abs(a-c),abs(b-d));
	return 0;
}