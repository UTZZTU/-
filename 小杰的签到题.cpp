#include <bits/stdc++.h>
using namespace std;
int t,f[1010],c[1010],n,b;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>f[i];
		cin>>b;
		sort(f+1,f+1+n);
		if(n<=3)
		cout<<f[n]+b<<endl;
		else
		{
			for(int i=1;i<=3;i++)
			{
				c[i]=f[i]+b;
			}
			for(int i=4;i<=n;i++)
			{
				c[i]=max(f[i],c[i-3])+b;
			}
			cout<<c[n]<<endl;
		}
	}
	return 0;
}