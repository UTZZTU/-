#include <bits/stdc++.h>
using namespace std;
int t,maxx,n,f[200010],ans;
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		scanf("%d",&f[j]);
		ans=0,maxx=0;
		for(int j=1;j<=n;j++)
		{
		    if(f[j]>maxx&&(j==n||f[j]>f[j+1]))
		    ans++;
		    maxx=max(maxx,f[j]);
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}