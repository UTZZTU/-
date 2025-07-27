#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,b[110],res,num=2023;
void solve()
{
	cin>>n>>k;
	res=1;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		res*=b[i];
	}
	if(num%res!=0) cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=k-1;i++) cout<<1<<" ";
		cout<<num/res<<endl;
	}
}
signed main ()
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
}