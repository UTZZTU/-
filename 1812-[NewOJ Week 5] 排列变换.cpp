#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],id[100010],k,res,maxx;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		b[k]=i;
	}
	for(int i=1;i<=n;i++)
	{
		id[i]=b[a[i]];
		if(maxx>id[i]) res++;
		maxx=max(maxx,id[i]);
	}
	cout<<res;
	return 0;
}