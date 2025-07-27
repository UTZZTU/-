#include <iostream>
using namespace std;
typedef long long ll;
ll a[510][510];
int main ()
{
	ll n,m,k,i,j,w,e,b,sum=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>w;
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+w;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(e=i;e<=n;e++)
			{
				for(b=j;b<=m;b++)
				{
					if(a[e][b]-a[e-i][b]-a[e][b-j]+a[e-i][b-j]<=k)
					sum++;
				}
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
