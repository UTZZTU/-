#include <bits/stdc++.h>
using namespace std;
int f[200010],n,a[200010],sum;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=a[i]-a[i-1];
		sum+=f[i];
	}
	if(sum&1)
	cout<<"NO";
	else
	cout<<"YES";
	return 0;
}