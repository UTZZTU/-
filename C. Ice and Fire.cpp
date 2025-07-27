#include <bits/stdc++.h>
using namespace std;
int dp[200010],t,n,js;
string s;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		getchar();
		cin>>s;
		for(int i=2;i<=n;i++)
		{
			if(i==2)
			{
				dp[i]=1;
				js=1;
			}
			else
			{
				if(s[i-2]!=s[i-3])
				{
					dp[i]=dp[i-1]+js;
					js=1;
				}
				else
				{
					dp[i]=dp[i-1];
					js++;
				}
			}
			printf("%d ",dp[i]);
		}
		printf("\n");
	}
	return 0;
}