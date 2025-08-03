#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],pre[200010];
string s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	cin>>s;
	ll sum=0;
	int l=0,r=n-1;
	while(l<r)
	{
		for(l;l<n&&s[l]=='R';l++) ;
		for(r;r>=0&&s[r]=='L';r--) ;
		if(l<r)
		{
//			cout<<l<<" "<<r<<endl;
			sum+=pre[r+1]-pre[l];
			l++,r--;
		}
		
	}
	cout<<sum<<endl;
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