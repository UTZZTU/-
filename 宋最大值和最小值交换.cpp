#include<stdio.h>
int main()
{
	int n,t,w,i,j,max=-99999,min=99999,*p,a[100];
	scanf("%d",&n);
	w=n;
	p=a;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    while(w--)
    {
    	if(*p>max)
    		max=*p;
		if(*p<min)
			min=*p;
			p++;
	}
	printf("%d %d\n",max,min);
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("%d %d\n",p[i],p[j]);
	printf("%d",a[0]);
	for(int i=1;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
 }
