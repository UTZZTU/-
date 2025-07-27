#include <iostream>
#include <algorithm>
using namespace std;
struct p
{
	int num,gs,m;
}s[10010];
bool cmp( p a,p b)
{
	if(a.m!=b.m)
	return a.m>b.m;
	else
	{
		if(a.gs!=b.gs)
		return a.gs>b.gs;
		else
		{
			return a.num<b.num;
		}
	}
}
int main ()
{
	int n,i,k,j,q,w;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s[i].gs=0;
		s[i].m=0;
	}
	for(i=1;i<=n;i++)
	{
		s[i].num=i;
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d%d",&q,&w);
			s[q].gs++;
			s[q].m+=w;
			s[i].m-=w;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(i=1;i<=n;i++)
	printf("%d %.2f\n",s[i].num,(double)s[i].m/100);
	return 0;
}