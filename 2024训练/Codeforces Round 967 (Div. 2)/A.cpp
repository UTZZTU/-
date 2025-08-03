#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n;
int f[110],t[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		t[i]=0;
	}	
	for(int i=1;i<=n;i++)
	{
		t[f[i]]++;
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,t[i]);
	}
	cout<<n-maxx<<endl;
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