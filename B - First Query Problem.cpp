#include <iostream>
using namespace std;
int f[100010],k,x,q,num,n;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&f[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&num,&k);
		if(num==1)
		{
			scanf("%d",&x);
			f[k]=x;
		}
		else
		printf("%d\n",f[k]);
	}
	return 0;
}