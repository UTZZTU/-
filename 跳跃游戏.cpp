#include <bits/stdc++.h>
using namespace std;
int n,f[100010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	if(f[1]<f[n])
	{
		cout<<"YES";
	}
	else cout<<"NO";
	return 0;
}