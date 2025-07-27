#include <iostream>
using namespace std;
int c[20010];
int main ()
{
	int v,n,i,w,a;
	scanf("%d",&v);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		for(i=v;i>=a;--i)
		{
			c[i]=max(c[i],a+c[i-a]);
		}
	}
	printf("%d",v-c[v]);
	return 0;
}
