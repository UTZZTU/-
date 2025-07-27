#include <iostream>
struct p
{
	int gs,sz;
	int a[100];
}s[100010];
using namespace std;
int main ()
{
	int n,i,j,max=0,dj;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i].gs);
		for(j=0;j<s[i].gs;j++)
		{
			scanf("%d",&s[i].a[j]);
		}
		s[i].sz=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<s[i].gs;j++)
		{
			s[i].sz+=s[s[i].a[j]].gs;
		}
		if(s[i].sz>max)
		{
			max=s[i].sz;
			dj=i;
		}	
	}
	printf("%d %d",dj,max);
	return 0;
}