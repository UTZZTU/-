#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll a1[1000010],a2[1000010],n,pre[1000010],post[1000010],premax[1000010],postmax[1000010],maxx,pp[1000010],qq[1000010];
void solve()
{
	maxx=-0x3f3f3f3f3f3f3f3f;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a2[i];
	}
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a1[i];
	}
	post[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		post[i]=post[i+1]+a2[i];
	}
	premax[1]=a2[1]-a1[1];
	pp[1]=a2[1];
	for(int i=2;i<=n;i++)
	{
		premax[i]=max(premax[i-1],a2[i]-a1[i]);
		pp[i]=max(pp[i-1],a2[i]);
	}
	postmax[n]=a1[n]-a2[n];
	postmax[n+1]=0;
	qq[n]=a1[n];
	for(int i=n-1;i>=1;i--)
	{
		postmax[i]=max(postmax[i+1],a1[i]-a2[i]);
		qq[i]=max(qq[i+1],a1[i]);
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,pre[i]+post[i]);
//		cout<<"666: "<<pre[i]+post[i]<<" ";
		if(i-1>=1&&i+1<=n)
		maxx=max(maxx,pre[i]+post[i]+premax[i-1]+postmax[i+1]);
//		cout<<maxx<<" ";
		if(i+1<=n)
		maxx=max(maxx,pre[i]+post[i]+qq[i+1]-a1[i]);
//		cout<<maxx<<" ";
		if(i-1>=1)
		maxx=max(maxx,pre[i]+post[i]+pp[i-1]-a2[i]);
//		cout<<maxx<<" ";
//		cout<<maxx<<endl;
	}
	cout<<maxx<<endl;
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
// a+c+d  => a+b+c