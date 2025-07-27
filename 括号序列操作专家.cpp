#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,res,ans;
string s;
signed main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		res=ans=0;
		getchar();
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(') res++;
		}
		if(res*2!=n)
		{
			printf("-1\n");
			continue;
		}
		res=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(') res++;
			else 
			{
				res--;
				if(res<0) ans-=res;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}