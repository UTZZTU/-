#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m,f[1010],cnt;
int find(int x)
{
	while(x!=f[x]) x=f[x]=f[f[x]];
	return x;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		int eu=find(u),ev=find(v);
		if(eu!=ev) f[eu]=ev;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i) cnt++; 
	}
	cout<<cnt-1;
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