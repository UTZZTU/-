#include <iostream>
#include <cstdio>
using namespace std;
int a,prime[50]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
int main()
	{
		while(cin>>a)
			{	 
				int dp[242]={1};
				for(int i=1;i<=46;i++)
					{
						for(int j=prime[i];j<=200;j++)
							dp[j]+=dp[j-prime[i]];
					}
				cout<<dp[a]<<endl;
			}
		return 0;
	}