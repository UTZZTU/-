#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,f[100010],res,ans;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		res=ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
			ans+=f[i];
		}
		ans/=n;
		for(int i=1;i<=n;i++)
		{
			if(f[i]>ans) res+=f[i]-ans;
		}
		cout<<res<<endl;
	}
	return 0;
}