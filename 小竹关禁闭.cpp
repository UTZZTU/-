#include <bits/stdc++.h>
using namespace std;
int n,k,a[2010],maxx,f[2010];
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=a[i];
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=i+k+1;j<=n;j++)
    	{
    		f[j]=max(f[j],a[j]+f[i]);
    		maxx=max(maxx,f[j]);
		}
	}
	cout<<maxx;
	return 0;
}