#include <bits/stdc++.h>
using namespace std;
struct node
{
	int value;
	int pos;
}s[100010];
bool cmp(node a,node b)
{
	return a.value<b.value;
}
int t,n,a[100010],b[100010],f[100010];
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			b[j]=a[j];
			s[j].pos=j;
			s[j].value=a[j];
		}
		sort(b+1,b+1+n);
		sort(s+1,s+1+n,cmp);
		printf("Case #%d:",i);
		for(int j=1;j<=n;j++)
		{
			f[j]=-1;
			int pos=upper_bound(b+1,b+1+n,2*a[j])-b;
			pos--;
			while(pos>=1)
			{
				if(s[pos].pos!=j)
				{
					f[j]=s[pos].value;
					break;
				}
				else pos--;
			}
			printf(" %d",f[j]);
		}
		printf("\n");
	}
	return 0;
}