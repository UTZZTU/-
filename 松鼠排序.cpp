#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],res,f[100010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		f[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			res++;
			int x=b[i];
			b[i]=a[i];
			b[f[a[i]]]=x;
			f[x]=f[a[i]];
			f[a[i]]=i;
		}
	}
	printf("%d",res);
	return 0;
}