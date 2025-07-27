#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,ans1,ans2,f[10010];
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		ans+=f[i];
	}
	ans/=n;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>ans)
		ans1+=f[i]-ans;
		else if(f[i]<ans)
		ans2+=ans-f[i];
	}
	cout<<min(ans1,ans2);
	return 0;
}