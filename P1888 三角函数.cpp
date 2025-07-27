#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a,b,c,maxx,minn,ys;
	cin>>a>>b>>c;
	maxx=max(a,max(b,c));
	minn=min(a,min(b,c));
	ys=__gcd(maxx,minn);
	maxx/=ys,minn/=ys;
	cout<<minn<<"/"<<maxx;
	return 0;
}