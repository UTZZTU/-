#include <bits/stdc++.h>
using namespace std;
int a,b,t;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<min((int)floor((a+b)/3.0),min(a,b))<<endl;
	}
	return 0;
}
