#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[30],t,n;
int main ()
{
	f[1]=3;
	for(int i=2;i<=29;i++)
	f[i]=f[i-1]*3;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}