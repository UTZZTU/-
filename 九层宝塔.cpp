#include<iostream>
using namespace std;
long long int dp[1000000];
int mod = 1e9 + 7;
int main()
{
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			dp[j] += dp[j - i];
			dp[j] %= mod;
		}
	}
	cout << (dp[n] - 1)%mod;
	return 0;
}