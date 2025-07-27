#include <bits/stdc++.h>
using namespace std;
int n,f[100010],sum,pre[100010],cnt;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		sum+=f[i];
		pre[i]=pre[i-1]+f[i];
	}
	for(int i=1;i<n;i++)
	{
		if(pre[i]*2==sum) cnt++;
	}
	cout<<cnt<<endl;
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