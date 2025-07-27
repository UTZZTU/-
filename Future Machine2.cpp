#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[1000010],b[1000010];
int main ()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	sort(b,b+m);
	for(int i=0;i<=n-1;i++)
	{
		if(a[i]==x) continue;
		int pos=upper_bound(b,b+m,a[i])-b;
		if(pos==m)
		{
			if(x>a[i]) x=a[i];
			else
			{
				x=max(x,b[pos-1]);
			}
		}else if(pos==0)
		{
			if(x<a[i])
			{
				x=a[i];
			}
			else
			{
				x=min(x,b[pos]);
			}
		}
		else
		{
			if(x>a[i]) x=a[i];
			else
			{
				x=max(x,b[pos-1]);
			}
			if(x<a[i])
			{
				x=a[i];
			}
			else
			{
				x=min(x,b[pos]);
			}
		}
		
	}
	printf("%d\n",x);
	return 0;
}