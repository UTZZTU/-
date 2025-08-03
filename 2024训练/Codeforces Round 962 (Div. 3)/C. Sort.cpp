#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[200010][30],p[200010][30],n,q;
string a,b;
void solve()
{
	cin>>n>>q;
	cin>>a>>b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			f[i+1][j]=0;
		}
		f[i+1][a[i]-'a']++;
		for(int j=0;j<26;j++)
		{
			f[i+1][j]+=f[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			p[i+1][j]=0;
		}
		p[i+1][b[i]-'a']++;
		for(int j=0;j<26;j++)
		{
			p[i+1][j]+=p[i][j];
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int res=r-l+1;
		for(int i=0;i<26;i++)
		{
			if(f[r][i]-f[l-1][i]>=p[r][i]-p[l-1][i]) res-=(p[r][i]-p[l-1][i]);
			else if(f[r][i]-f[l-1][i]<p[r][i]-p[l-1][i]) res-=(f[r][i]-f[l-1][i]);
		}
		cout<<res<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}