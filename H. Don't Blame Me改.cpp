#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
 #define int long long
typedef pair<int,int> PII;
typedef unsigned long long ULL;
const int N = 4e5 + 10;
int mod = 1e9 + 7;
int dp[N][64];
int a[N];
void solve()
{
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		dp[i][a[i]] = 1;
		for(int j = 0;j <= 63;j++)
		{
			dp[i][j] = (dp[i][j] + dp[i - 1][j])%mod;
			dp[i][j&a[i]] = (dp[i][j&a[i]] + dp[i - 1][j])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=63;j++)
		printf("%d ",dp[i][j]);
		printf("\n");
	}
	int ans = 0;
	for(int i = 0;i <= 63;i++)
	{
		int cnt = 0;
		for(int j = 0;j < 6;j++)
		{
			if((i >> j)&1)
			{
				cnt ++;
			}
		}
		if(cnt == k)
		{
			ans = (ans + dp[n][i])%mod;
		}
	}
	cout << ans <<"\n";
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j <= 63;j++)
		{
			dp[i][j] = 0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0 );
	cin.tie(0);cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve(); 
	}
}