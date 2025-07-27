#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int zx,q[500050];
struct f
{
	int a,b;
}s[500010];
int main ()
{
	int n,m,w[10010],i,x,y,max=0,k;
	memset(w,0,sizeof(w));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&s[i].a,&s[i].b);
		w[s[i].a]++;
		w[s[i].b]++;
	}
	for(i=1;i<=n;i++)
	{
		if(w[i]>max)
		{
			max=w[i];
			zx=i;
		}
	}
	k=0;
	for(i=0;i<m;i++)
	{
		if(s[i].a==zx)
		{
			q[k]=s[i].b;
			k++;
		}
		if(s[i].b==zx)
		{
			q[k]=s[i].a;
			k++;
		}
	}
	sort(q,q+k);
	for(i=0;i<k-1;i++)
	{
		printf("%d ",q[i]);
	}
	printf("%d",q[i]);
	return 0;
}
