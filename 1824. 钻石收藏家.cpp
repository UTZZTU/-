#include <bits/stdc++.h>
using namespace std;
int f[1010],ans;
int main ()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		int j=upper_bound(f+1,f+1+n,f[i]+k)-f;
		if(j<=n)
		ans=max(ans,j-i);
		else
		ans=max(ans,n-i+1);
	}
	cout<<ans;
	return 0;
}