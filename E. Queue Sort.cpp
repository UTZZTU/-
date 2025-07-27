#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010];
bool check(int pos)
{
	for(int i=pos+1;i<=n;i++)
	{
		if(a[i]<a[i-1]) return false;
	}
	return true;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		int minn=1e9+10,pos=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<minn)
			{
				minn=a[i];
				pos=i;
			}
		}
		if(check(pos))
		{
			printf("%d\n",pos-1);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}