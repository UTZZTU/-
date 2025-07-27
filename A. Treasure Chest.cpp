#include <bits/stdc++.h>
using namespace std;
int t,x,y,k;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>k;
		if(x>y) cout<<x<<endl;
		else 
		{
			x+=min(k,y-x);
			cout<<2*y-x<<endl;
		}
	}
	return 0;
}