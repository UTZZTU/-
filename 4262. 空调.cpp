#include <bits/stdc++.h>
using namespace std;
int f[100010],cf[100010],ans1,ans2,n;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	for(int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		f[i]-=k;
	}
	for(int i=1;i<=n;i++)
	{
		cf[i]=f[i]-f[i-1];
		if(cf[i]>0)
		ans1+=cf[i];
		else
		ans2+=cf[i];
	}
	cout<<max(abs(ans1),abs(ans2));
	return 0;
}