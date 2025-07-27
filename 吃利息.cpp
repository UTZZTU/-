#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int k,n;
	cin>>k>>n;
	for(int i=1;i<=n;i++)
	{
		int u=k/10;
		if(u>5)
		u=5;
		k+=u+5;
	}
	cout<<k;
	return 0;
}