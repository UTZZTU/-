#include <iostream>
 
#define SIZE 100001
 
using namespace std;
 
int dp[SIZE];
 
int main(int argc, char** argv)
{
	int t, n, c, i;
	
	scanf("%d%d", &n, &t);
	while (n--)
	{
		scanf("%d", &c);
		for (i = t; i >= c; --i) // ÌîÂúĞÍ±³°ü
		{
			dp[i] = max(dp[i], c + dp[i-c]);
		}
	}
	
	printf("%d", dp[t]);
	
	return 0;
}
