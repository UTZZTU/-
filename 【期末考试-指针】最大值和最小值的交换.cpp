#include <stdio.h>
int main ()
{
	int n,i,c[100],max=-9999999,min=9999999,q1,q2,t,*a1,*a2;
	a1=&max;
	a2=&min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]<*a2)
		{
			*a2=c[i];
			q2=i;
		}
		if(c[i]>*a1)
		{
			*a1=c[i];
			q1=i;
		}
	}
	t=c[q1];
	c[q1]=c[q2];
	c[q2]=t;
	for(i=0;i<n-1;i++)
	{
		printf("%d ",c[i]);
	}
	printf("%d",c[n-1]);
	return 0;
}
