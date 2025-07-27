#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
string s;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		ll a[210]={0},vis[210]={0};
		int judge=0,pd=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		getchar();
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			pd=0;
			if(s[i]=='1')
			{
				int mb=a[i+1];
				for(int j=i+1;j<s.size();j++)
				{
					if(s[j]=='0'&&vis[j+1]==0&&a[j+1]==mb)
					{
						pd=1;
						vis[j+1]=1;
						break;
					}
				}
				if(pd==0)
				{
					judge=1;
					break;
				}
			}
		}
		if(judge)
		printf("1\n");
		else
		printf("0\n");
	}
	return 0;
}