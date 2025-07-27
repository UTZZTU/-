#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,m,l,r,res1,res2;
signed main ()
{
	cin>>a>>m>>l>>r;
	res1=(l-a)/m;
	res2=(r-a)/m;
	if(a+res1*m<l) res1++;
	if(a+res2*m>r) res2--;
	if(res1>res2)
	cout<<0;
	else
	cout<<res2-res1+1;
	return 0;
}