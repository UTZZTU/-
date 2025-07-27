#include <bits/stdc++.h>
using namespace std;
int n,k,x,f[200010],pre[200010];
void solve()
{
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	int k1=k,x1=x;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+f[i];
	}
	int maxx=-2e8;
	for(int i=n;i>=1;i--)
	{
		int l=i-x;
		l=max(l,0);
		maxx=max(maxx,-(pre[i]-pre[l])+pre[l]-pre[0]);
		if(k1==0) break;
		else k1--;
		if(i==1) maxx=max(maxx,0);
	}
//	if(k1) maxx=max(maxx,0);
	cout<<maxx<<endl;
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
