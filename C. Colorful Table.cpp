#include <bits/stdc++.h>
using namespace std;
int n,k,f[100100],mx1[100100],mx2[100100],cnt[100100];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		mx1[i]=max(f[i],mx1[i-1]);
		cnt[f[i]]++;
	}
	for(int i=n;i>=1;i--) mx2[n-i+1]=max(mx2[n-i],f[i]);
	for(int i=1;i<=k;i++)
	{
		if(cnt[i])
		{
			int pos1=lower_bound(mx1+1,mx1+1+n,i)-mx1;
			int pos2=lower_bound(mx2+1,mx2+1+n,i)-mx2;
			pos2=n+1-pos2;
			cout<<2*(pos2-pos1+1)<<" ";
//			cout<<"///"<<endl;
//			cout<<i<<" "<<pos1<<" "<<pos2<<endl;
		}
		else cout<<0<<" ";
	}
	cout<<endl;
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