#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main ()
{
	cin>>n;
	while(n!=1)
	{
		if(n&1)
		n--;
		else
		{
			n>>=1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}