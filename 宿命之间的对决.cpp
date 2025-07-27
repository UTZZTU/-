#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main ()
{
	cin>>n;
	if(n==1)
	{
		cout<<"yukari";
	}
	else
	{
		if((n-1)&1)
		cout<<"kou";
		else
		cout<<"yukari";
	}
	return 0;
}