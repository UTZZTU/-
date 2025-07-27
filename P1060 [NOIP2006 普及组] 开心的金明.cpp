#include <iostream>
using namespace std;
int c[30010];
int main ()
{
	int n,m,i,w,a[25],b[25];
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=1;i<=m;++i)
	{
		for(w=n;w>=a[i];--w)
		{
			c[w]=max(c[w],a[i]*b[i]+c[w-a[i]]);
		}
	}
	printf("%d",c[n]);
	return 0;
}
