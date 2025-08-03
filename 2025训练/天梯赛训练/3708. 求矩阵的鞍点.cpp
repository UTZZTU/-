#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m,h[15],l[15],f[15][15],flag;
void solve()
{
	cin>>n>>m;
	for(int j=1;j<=m;j++)
	{
		l[j]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
			h[i]=max(h[i],f[i][j]);
			l[j]=min(l[j],f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(f[i][j]==h[i]&&f[i][j]==l[j])
			{
				flag=1;
				cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
	}
	if(!flag)  cout<<"NO"<<endl;
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