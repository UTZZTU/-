#include <bits/stdc++.h>
using namespace std;
int n,m,f[110],cnt;
int main ()
{
	cin>>n>>m;
	while(m)
	{
		f[++cnt]=m%n;
		m/=n;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(f[i]>=n-1) f[i]=0,f[i+1]++;
		else if(f[i]==1) f[i]=0;
		else if(f[i]!=0)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}