#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,ans;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>a>>b>>c;
		if(a+b+c>=2)
		ans++;
	}
	cout<<ans;
	return 0;
}