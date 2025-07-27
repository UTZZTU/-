#include <bits/stdc++.h>
using namespace std;
string s;
int dp[100010][50],minn=0x3f3f3f3f;
int get_num(char c)
{
	int res=0;
	for(int i=0;i<s.size();i++)
	{
		int minn;
		if(c>=s[i])
		{
			minn=min(c-s[i],s[i]-'a'+'z'-c+1);
		}
		else
		{
			minn=min(s[i]-c,c-'a'+'z'-s[i]+1);
		}
		res+=minn;
	}
	return res;
}
int main ()
{
	cin>>s;
//	for(int i=0;i<s.size();i++)
//	{
//		int x=s[i]-'a';
//		for(int j=0;j<26;j++)
//		{
//			int pos;
//			if(j>=x)
//			{
//				pos=min(j-x,26-j+x);
//			}
//			else
//			{
//				pos=min(x-j,26-x+j);
//			}
//			dp[i+1][j]=pos;
//			dp[i+1][j]+=dp[i-1][j];
//		}
//		
//	}
	for(int j=0;j<26;j++)
	{
//		minn=min(minn,dp[s.size()][j]);
        minn=min(minn,get_num((char)('a'+j)));
	}
	cout<<minn;
	return 0;
}