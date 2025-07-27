#include <bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
}s[10010];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int n,q[1010],m,f[1010],res,sum;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>q[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(res==n-1) break;
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(f[v]) continue;
		f[v]=1;
		res++;
		sum+=w;
		if(res==n-1) break;
	}
	if(res==n-1) cout<<sum<<endl;
	else cout<<-1<<endl;
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