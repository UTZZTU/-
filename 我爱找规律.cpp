#include <bits/stdc++.h>
using namespace std;
int n,f[1010];
int main ()
{
	f[1]=1,f[2]=2;
	cin>>n;
	if(n==1) cout<<1;
	else if(n==2) cout<<2;
	else
	{
		for(int i=3;i<=n;i++)
		{
			f[i]=f[i-2]+3;
		}
		cout<<f[n];
	}
	return 0;
}