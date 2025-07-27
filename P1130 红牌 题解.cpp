#include <iostream>
using namespace std;
int f[2010][2010];
int a[2010][2010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>a[j][i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		f[i][j] = std::min(f[i - 1][j], j == 1 ? f[i - 1][m] : f[i - 1][j - 1]) + a[i][j];
	}
	int ans=100000000;
	for(int i=1;i<=m;i++)
	ans=std::min(ans,f[n][i]);
	cout<<ans;
	return 0;
}