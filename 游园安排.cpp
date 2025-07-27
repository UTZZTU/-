#include <bits/stdc++.h>
using namespace std;
int pos[100010];
int dp[100010];
string str[100010];
int k=1;
void output(int x)
{
	if(x==pos[x])
	{
		cout<<str[x];
		return;
	}
	output(pos[x]);
	cout<<str[x];
}
int main ()
{
	string a,b;
	int pd=0;
	getline(cin,a);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			if(pd==0)
			{
				b+=a[i];
				pd=1;
			}
			else
			{
				str[k++]=b;
				b.clear();
				b+=a[i];
			}
		}
		else
		b+=a[i];
	}
	str[k++]=b;
	b.clear();
	for(int i=1;i<k;i++)
	{
		dp[i]=1;
		pos[i]=i;
		for(int j=1;j<i;j++)
		{
			if(str[i]>str[j]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
				pos[i]=j;
			}
			if(str[i]>str[j]&&dp[j]+1==dp[i]&&str[j]<str[pos[i]])
			{
				pos[i]=j;
			}
		}
	}
	int mx=1;
	for(int i=2;i<k;i++)
	{
		if(dp[i]>dp[mx])
		mx=i;
		if(dp[i]==dp[mx]&&str[i]<str[mx])
		mx=i;
	}
	output(mx);
	return 0;
}