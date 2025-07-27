#include <iostream>
using namespace std;
typedef long long ll;
ll a[1100][1100],b[1100][1100];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		cin>>a[i][j];
	}
	b[1][1]=a[1][1];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			b[i][j]=max(b[i-1][j],b[i-1][j-1])+a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,b[n][i]);
	}
	cout<<ans;
	return 0;
}