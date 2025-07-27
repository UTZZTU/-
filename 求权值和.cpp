#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
ll a[110][110];
int main ()
{
	memset(a,-1,sizeof(a));
	ll n,m,u,v,w;
	ll sum=0;
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=w;
	}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			sum+=0;
			else if(a[i][j]==-1)
			sum+=j*pow(10,9);
			else
			sum+=j*a[i][j];
		}
		printf("%lld\n",sum);
	}
	return 0;
}