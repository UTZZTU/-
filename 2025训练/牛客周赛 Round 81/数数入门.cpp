#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,f[1010][1010],flag;
void solve()
{
	flag=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>f[i][j];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(f[i][j]<=f[i+1][j]&&f[i][j]<=f[i+1][j+1]) ;
			else flag=1;
		}
	}
	if(flag) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
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