#include <bits/stdc++.h>
using namespace std;
int n,s,k,p,q,res;
int main ()
{
	cin>>n>>s>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>q;
		res+=p*q;
	}
	cout<<(res>=s?res:res+k);
	return 0;
}