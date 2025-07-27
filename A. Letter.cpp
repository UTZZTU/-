#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[55];
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	int l=1000,r=-1,u=1000,d=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='*')
			{
				l=min(l,j);
				r=max(r,j);
				u=min(u,i);
				d=max(d,i);
			}
		}
	}
	for(int i=u;i<=d;i++)
	{
		for(int j=l;j<=r;j++)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}