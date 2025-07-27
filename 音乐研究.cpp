#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1010],b[1010],ans,dif=0x3f3f3f3f3f3f3f3f;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	cin>>b[i];
	for(int i=1;i<=m-n+1;i++)
	{
		ans=0;
		for(int j=i;j<=i+n-1;j++)
		{
			ans+=(b[j]-a[j-i+1])*(b[j]-a[j-i+1]);
		}
		dif=min(dif,ans);
	}
	cout<<dif;
	return 0;
}