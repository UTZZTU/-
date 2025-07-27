#include <bits/stdc++.h>
using namespace std;
int n,k,a,b;
int main ()
{
	cin>>n>>k>>a>>b;
	if((n-1)*a<(k+n-2)*b)
	cout<<"2";
	else if((n-1)*a==(k+n-2)*b)
	cout<<"0";
	else
	cout<<"1";
	return 0;
}