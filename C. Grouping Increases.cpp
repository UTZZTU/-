#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
void solve()
{
	int cnt1=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2)
	{
		cout<<0<<endl;
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1]) cnt1++;
	}
	if(cnt1==n-1)
	{
		cout<<cnt1-1<<endl;
		return;
	}
	else if(cnt1==0)
	{
		cout<<0<<endl;
		return;
	}
	else
	{
		int res=0,pp1=0x3f3f3f3f,pp2=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=pp1&&a[i]<=pp2)
			{
				if(pp1<=pp2)
				{
					pp1=a[i];
				}
				else
				{
					pp2=a[i];
				}
			}
			else if(a[i]>pp1&&a[i]>pp2)
			{
				res++;
				if(pp1<=pp2)
				{
					pp1=a[i];
				}
				else
				{
					pp2=a[i];
				}
			}
			else
			{
				if(pp1<=pp2)
				{
					pp2=a[i];
				}
				else
				{
					pp1=a[i];
				}
			}
//			cout<<pp1<<" "<<pp2<<endl;
		}
		cout<<res<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}