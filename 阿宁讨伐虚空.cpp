#include <bits/stdc++.h>
using namespace std;
int x,l,r;
int main ()
{
	cin>>x>>l>>r;
	if(r<x)
	cout<<1.0000000<<endl;
	else if(l>x)
	cout<<0.0000000<<endl;
	else
	{
		printf("%.10f\n",(x-l)*1.0/(r-l+1));
	}
	return 0;
}