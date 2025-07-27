#include <bits/stdc++.h>
using namespace std;
int n,l,r,x;
int main ()
{
	cin>>n>>l>>r;
	x=min(n-1,r-l+l%n);
	cout<<x;
	return 0;
}