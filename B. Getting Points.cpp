#include <bits/stdc++.h>
using namespace std;
#define int long long
int tc,n,p,l,t;
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tc;
	while(tc--)
	{
		cin>>n>>p>>l>>t;
		int p1=l+2*t,week=(n+6)/7;
		int cnt=week/2;
		if(cnt*p1>=p)
		{
			int pp=ceil(p*1.0/p1);
			cout<<n-pp<<endl;
		}
		else
		{
			p-=cnt*p1;
			if(week&1)
			{
				p-=l;
				p-=t;
				if(p<=0) cout<<n-cnt-1<<endl;
				else
				{
					int pp=ceil(p*1.0/l);
					cout<<n-cnt-pp-1<<endl;
				}
			}
			else
			{
				int pp=ceil(p*1.0/l);
				cout<<n-cnt-pp<<endl;
			}
		}
	}
	return 0;
}