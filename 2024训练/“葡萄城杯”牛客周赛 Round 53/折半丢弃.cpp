#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[100010],a[100010];
bool check(int x)
{
	for(int i=0;i<=x;i++)
	{
		f[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x) f[a[i]]++;
		else
		{
			int y=a[i];
			while(y>x)
			{
				y/=2;
			}
			f[y]++;
		}
	}
	for(int i=x;i>=0;i--)
	{
		if(!f[i]) return false;
		f[i/2]+=f[i]-1;
	}
	return true;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=0,r=n-1;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l+1<<endl;
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