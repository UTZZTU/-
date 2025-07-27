#include <iostream>
using namespace std;
int main ()
{
	int n,x,i,k,a[1010],m=0;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k!=x)
		{
			a[m]=k;
			m++;
		}
	}
	for(i=0;i<m;i++)
	printf("%d ",a[i]);
	return 0;
}