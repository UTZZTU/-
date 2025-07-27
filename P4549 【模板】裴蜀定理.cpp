#include <bits/stdc++.h>
using namespace std;
int n,f[110],k,res;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k<0) k*=-1;
		res=gcd(res,k);
	}
	cout<<res;
	return 0;
}