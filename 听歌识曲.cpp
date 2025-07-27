#include <stdio.h>
int main ()
{
	int n,t,a[100010],i;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(t<=a[i])
		{
			printf("%d",i+1);
			break;
		}
		else
		t-=a[i];
	}
	return 0;
}
