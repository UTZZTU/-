#include <stdio.h>
typedef long long ll;
ll q[1010][1010];
int main ()
{
	ll n,m,i,j;
	scanf("%lld%lld",&n,&m);
	q[0][1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			q[i][j]=q[i-1][j]+q[i][j-1];
			q[i][j]%=1000000007;
		}
	}
	printf("%lld",q[n][m]);
	return 0;
}