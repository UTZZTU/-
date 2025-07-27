#include <bits/stdc++.h>
using namespace std;
int t,n,q,d[510],fa[510];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d",&d[i]);
		}
		if(n==3)
		{
			printf("1 2\n");
			printf("2 3\n");
			for(int i=1;i<=q;i++)
			{
				printf("-1 -1 -1\n");
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1) fa[i]=i;
				else fa[i]=i-1;
			}
			for(int i=1;i<n;i++)
			{
				printf("%d %d\n",i,i+1);
			}
			int p1=2,last=n,pre=-1;
			for(int i=1;i<=q;i++)
			{
				if(pre==-1)
				{
					if(d[i]==n-1)
					{
						printf("-1 -1 -1\n");
						continue;
					}
					pre=d[i];
					int cnt=last,pp=1,pos=last;
					while(pp<d[i]-1)
					{
						cnt=fa[cnt];
						pp++;
					}
					printf("%d %d %d\n",cnt,fa[cnt],p1);
					last=fa[cnt];
					fa[cnt]=p1;
					p1=pos;
				}
				else
				{
					if(d[i]==pre)
					{
						printf("-1 -1 -1\n");
					}
					else if(d[i]>pre)
					{
						int cnt=last,pp=1,post=last;
						while(pp<d[i]-pre)
						{
							cnt=fa[cnt];
							pp++;
						}
						printf("%d %d %d\n",cnt,fa[cnt],p1);
						last=fa[cnt];
						fa[cnt]=p1;
						p1=post;
					}
					else
					{
						int cnt=p1,pp=1,post=p1;
						while(pp<pre-d[i])
						{
							cnt=fa[cnt];
							pp++;
						}
						printf("%d %d %d\n",p1,fa[p1],last);
						int tt=p1;
						p1=fa[p1];
						fa[tt]=last;
						last=post;
					}
					pre=d[i];
				}
			}
		}
	}
	return 0;
}