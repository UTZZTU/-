#include <bits/stdc++.h>
using namespace std;
int n,l,res,k;
int main ()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k>=l) res++;
	}
	cout<<res;
	return 0;
}