#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int m;
struct p
{
	int a[105];
	int gs;
}s[10005];
bool cmp(p a,p b)
{
	int i;
	if(a.gs!=b.gs)
	return a.gs>b.gs;
	else
	{
		for(i=1;i<=m;i++)
		{
			if(a.a[i]!=b.a[i])
			return a.a[i]<b.a[i];
		}
	}
}
int main ()
{
	int n,i,j,q=2,pd=0,w,bd[105];
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&s[i].a[j]);
			}
			s[i].gs=1;
		}
		else
		{
			for(j=1;j<=m;j++)
			scanf("%d",&bd[j]);
		
			for(j=1;j<q;j++)
			{	
			    pd=0;
				for(w=1;w<=m;w++)
				{
					if(bd[w]==s[j].a[w])
					pd++;
					else
					break;
				}
				if(pd==m)
				{
					s[j].gs++;
					break;
				}
			}
			if(pd!=m)
			{
				for(j=1;j<=m;j++)
				{
					s[q].a[j]=bd[j];
				}
				s[q].gs=1;
				q++;
			}
		}
	}
	sort(s+1,s+q,cmp);
	printf("%d\n",q-1);
	for(i=1;i<q;i++)
	{
		printf("%d ",s[i].gs);
		for(j=1;j<m;j++)
		printf("%d ",s[i].a[j]);
		printf("%d",s[i].a[j]);
		printf("\n");
	}
	return 0;
}
