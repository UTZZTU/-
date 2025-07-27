#include <bits/stdc++.h>
using namespace std;
int n,a[1010],b[1010];
bool st[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st[i]=false;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])
		{
			st[i]=true;
		}
		for(int j=i-1;j;j--)
		{
			if(a[i]==b[j]&&a[j]<b[j])
			{
				st[j]=true;
			}
			else if(a[j]>b[j]||a[i]>b[j]||a[j]>a[i])
			{
				break;
			}
		}
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==b[j]&&a[j]<b[j])
			{
				st[j]=true;
			}
			else if(a[j]>b[j]||a[i]>b[j]||a[j]>a[i])
			{
				break;
			}
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}