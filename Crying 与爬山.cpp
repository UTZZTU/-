#include <bits/stdc++.h>
using namespace std;
int n,f[100010],res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=2;i<=n-1;i++)
	{
		if(f[i]<f[i-1]&&f[i]<f[i+1]) res++;
	}
	cout<<res;
	return 0;
}