#include <bits/stdc++.h>
using namespace std;
int n,a;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>a;
		if(a&1) cout<<0<<" "<<0<<endl;
		else cout<<a/4+a%4/2<<" "<<a/2<<endl;
	}
	return 0;
}