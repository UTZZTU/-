#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
int main ()
{
	cin>>a>>b>>c;
	if(a%c!=0||b%c!=0)
	{
		cout<<-1;
	}
	else
	{
		cout<<(a/c)*(b/c);
	}
	return 0;
}