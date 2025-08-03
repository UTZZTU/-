#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200010],f[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1) f[a[i]]=1;
		else
		{
			if((a[i]-1>=1&&f[a[i]-1]==1)||(a[i]+1<=n&&f[a[i]+1]==1)) 
			{
				f[a[i]]=1;
			}
			else
			{
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	cout<<"YES"<<endl;
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