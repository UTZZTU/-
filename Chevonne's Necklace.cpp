#include <iostream>
using namespace std;
long long N=998244353;
int f[2020];
int a[2020];
int main ()
{
	f[0]=1;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		continue;
		for(int j=n;j>=a[i];j--)
		{
			f[j]=(f[j]+f[j-a[i]])%N;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(f[i]!=0)
		{
			printf("%d %d",i,f[i]);
			return 0;
		}
	}
	return 0;
}