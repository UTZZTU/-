#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,H,h[100],res,flag;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k>>H;
		res=0;
		for(int i=1;i<=n;i++)
		{
			cin>>h[i];
			flag=0;
			if(h[i]!=H)
			{
				for(ll j=1;j<=m-1;j++)
				{
					if(j*k==abs(h[i]-H))
					{
						flag=1;
						break;
					}
				}
			}
			if(flag)
			res++;
		}
		cout<<res<<endl;
	}
	return 0;
}