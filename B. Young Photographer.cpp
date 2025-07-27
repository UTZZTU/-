#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,x0;
pair<int,int> p[110];
int flag=1,l,r;
void solve()
{
	cin>>n>>x0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].fi>>p[i].se;
		if(p[i].fi>p[i].se) swap(p[i].fi,p[i].se);
	}
	l=p[1].fi,r=p[1].se;
	for(int i=2;i<=n;i++)
	{
		if(p[i].fi>r||p[i].se<l)
		{
			flag=0;
			break;
		}
		else
		{
			l=max(l,p[i].fi);
			r=min(r,p[i].se);
		}
	}
	if(!flag) cout<<-1<<endl;
	else
	{
		if(x0>=l&&x0<=r) cout<<0<<endl;
		else if(x0<l) cout<<l-x0<<endl;
		else cout<<x0-r<<endl;
	}
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