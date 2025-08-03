#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,m,a[200010],b[200010],pre[200010],post[200010],res1,res2,minn=0x3f3f3f3f3f3f3f3f;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	priority_queue<int> p,q;
	for(int i=1;i<=m;i++)
	{
		p.push(a[i]);
		res1+=a[i];
	}
	pre[m]=res1;
	for(int i=m+1;i<=n;i++)
	{
		if(a[i]<p.top())
		{
			res1-=p.top();
			p.pop();
			res1+=a[i];
			p.push(a[i]);
		}
		pre[i]=res1;
	}
	for(int i=n;i>=n-m+1;i--)
	{
		q.push(b[i]);
		res2+=b[i];
	}
	post[n-m+1]=res2;
	for(int i=n-m;i>=1;i--)
	{
		if(b[i]<q.top())
		{
			res2-=q.top();
			q.pop();
			res2+=b[i];
			q.push(b[i]);
		}
		post[i]=res2;
	}
	for(int i=m;i<=n-m;i++)
	{
		minn=min(minn,pre[i]+post[i+1]);
	}
	cout<<minn<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}