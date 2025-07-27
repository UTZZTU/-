#include <iostream>
using namespace std;
int c[1005];
int main (int argc, char** argv)
{
	int a[101],b[101],t,m,i,j;
	scanf("%d%d",&t,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=1;i<=m;++i)
	{
		for(j=t;j>=a[i];--j)
		{
			c[j]=max(b[i]+c[j-a[i]],c[j]);
		}
	}
	printf("%d",c[t]);
	return 0;
 }
