#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
int n,m;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int N=405;
long long dp[N][N];
ll sum=0;
void input()
{
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		dp[u][v]=min(dp[u][v],w);
	}
}
void floyd()
{
	for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
}
int main ()
{
	cin>>n>>m;
	input();
    floyd();
    for(ll i=1;i<=n;i++)
    {
    	sum=0;
    	for(ll j=1;j<=n;j++)
    	{
    		if(i==j)
    		continue;
			else if(dp[i][j]==INF)
    		{
    			sum+=j*pow(10,9);
			}
			else
			sum+=j*dp[i][j];
		}
		cout<<sum<<endl;
	}
    return 0;
}
