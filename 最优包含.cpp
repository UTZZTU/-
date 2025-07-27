#include <iostream>
using namespace std;
int dp[1010][1010];
int main ()
{
	string s1,s2;
	cin>>s1>>s2;
	for(int i=1;i<=s1.size();i++)
	dp[i][0]=0;
	for(int j=1;j<=s2.size();j++)
	dp[0][j]=99999999;
	for(int i=1;i<=s1.size();i++)
	{
		for(int j=1;j<=s2.size();j++)
		{
			if(s1[i-1]==s2[j-1])
			dp[i][j]=dp[i-1][j-1];
			else
			dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+1);
		}
	}
	cout<<dp[s1.size()][s2.size()];
	return 0;
}
