#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main ()
{
	cin>>a>>b;
	if(b>0)
	cout<<abs(a);
	else
	cout<<-1*abs(a);
	return 0;
}