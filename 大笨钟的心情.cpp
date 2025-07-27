#include <stdio.h>
int main ()
{
	int a[24],i,n;
	for(i=0;i<24;i++)
	{
		scanf("%d",&a[i]);
	}
	while(~scanf("%d",&n))
	{
		if(n<0||n>23)
		break;
		else
		{
			if(a[n]>50)
			printf("%d Yes\n",a[n]);
			else
			printf("%d No\n",a[n]);
		}
	}
	return 0;
}