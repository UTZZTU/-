#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,lx,rx,ly,ry,lz,rz;
ll f[110][110][110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				ll p;
				cin>>p;
				f[i][j][k]=p+f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k]+f[i][j][k-1]-f[i-1][j][k-1]-f[i][j-1][k-1]+f[i-1][j-1][k-1];
			}
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>lx>>rx>>ly>>ry>>lz>>rz;
		cout<<f[rx][ry][rz]-f[lx-1][ry][rz]-f[rx][ly-1][rz]-f[rx][ry][lz-1]+f[lx-1][ly-1][rz]+f[lx-1][ry][lz-1]+f[rx][ly-1][lz-1]-f[lx-1][ly-1][lz-1]<<endl;
	}
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