#include <bits/stdc++.h>
using namespace std;
int n,f[1010],res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f[i]>f[j]) res++;
		}
	}
	cout<<res;
	return 0;
}