#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string u;
ll f[1000010],dp[1000010],k,ans,maxx=0;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		ans=0;
		if(u[i]=='1')
		{
			while(i<u.size()&&u[i]=='1')
			{
				ans++;
				i++;
			}
			k++;
			if(k&1)
			f[k]=ans*ans;
			else
			f[k]=-ans*ans;
		}
	}
	for(int i=1;i<=k;i++)
	{
		dp[i]=max(dp[i-1]+f[i],f[i]);
		if(dp[i]>maxx)
		{
			maxx=dp[i];
		}
	}
	cout<<maxx<<endl;
	return 0;
}