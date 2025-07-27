#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[110],maxx;
bool solve(int x)
{
	set<int> st;
	for(int i=1;i<=n;i++)
	{
		st.insert(a[i]%x);
		if(st.size()>2) return false;
	}
	return (int)st.size()==2;
}
signed main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxx=0;
		int res1=0,res2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]&1) res1++;
			else res2++;
			maxx=max(maxx,a[i]);
		}
		if(res1&&res2)
		{
			puts("2");
		}
		else
		{
			if(n==2)
			{
				puts("1000000000000000000");
			}
			else
			{
				int f=4;
				while(1)
				{
					if(solve(f))
					{
						cout<<f<<endl;
						break;
					}
					f*=2;
				}
			}
		}
//		for(int i=1;i<=maxx;i++)
//		{
//			if(solve(i))
//			{
//				cout<<i<<endl;
//			}
//		}
//		cout<<endl<<endl;
	}
	return 0;
}