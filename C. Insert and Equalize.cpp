#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,f[200010],sum;
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
		}
		sort(f+1,f+1+n);
		if(n==1) 
		{
			cout<<1<<endl;
			continue;
		}
		int gcds;
		for(int i=2;i<=n;i++)
		{
			if(i==2)
			{
				gcds=f[i]-f[i-1];
			}
			else
			{
				gcds=__gcd(gcds,f[i]-f[i-1]);
			}
	    }
	    for(int i=1;i<=n;i++)
	    {
	    	sum+=(f[n]-f[i])/gcds;
		}
		int i=n-1,pp=-gcds;
		for(i;i>=1;i--)
		{
			if(f[i]!=f[n]+pp)
			{
				break;
			}
			pp-=gcds;
		}
		sum+=(n-i);
		cout<<sum<<endl;
	}
	return 0;
}