#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[200010],res1,res2,maxx1,maxx2;
void solve()
{
	res1=res2=maxx1=maxx2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(f[i]&1) 
		{
			res1++;
			maxx1=max(maxx1,f[i]);
		}
		else
		{
			res2++;
			maxx2=max(maxx2,f[i]);
		}
	}
	sort(f+1,f+1+n);
	if(res1==n||res2==n)
	{
		cout<<0<<endl;
	}
	else
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]&1)
			{
				continue;
			}
			else
			{
				if(maxx1>f[i])
				{
					sum++;
					maxx1+=f[i];
				}
				else
				{
					maxx1+=maxx2;
					sum+=2;
				}
			}
		}
		cout<<sum<<endl;
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