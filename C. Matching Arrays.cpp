#include <bits/stdc++.h>
using namespace std;
int t,n,x,a[200010],b[200010],res;
struct node
{
	int num,pos;
}s1[200010],s2[200010];
bool cmp(node x,node y)
{
	return x.num<y.num;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s1[i].num=a[i];
			s1[i].pos=i;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			s2[i].num=b[i];
			s2[i].pos=i;
		}
		sort(s1+1,s1+1+n,cmp);
		sort(s2+1,s2+1+n,cmp);
		for(int i=1,j=n-x+1;i<=x&&j<=n;i++,j++)
		{
			int pp=s1[j].pos;
			b[pp]=s2[i].num;
			if(a[pp]>b[pp]) res++;
		}
		for(int i=x+1,j=1;i<=n;i++,j++)
		{
			int pp=s1[j].pos;
			b[pp]=s2[i].num;
			if(a[pp]>b[pp]) res++;
		}
		if(res!=x) puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				printf("%d ",b[i]);
			}
			printf("\n");
		}
	}
	return 0;
}