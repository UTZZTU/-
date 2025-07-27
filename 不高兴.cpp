#include <stdio.h>
int main ()
{
	int c[7];
	int a,b,sum,s=0,w=0;
	for(int i=0;i<=6;i++)
	{
		scanf("%d %d",&a,&b);
		sum=a+b;
		if(sum>s)
		s=sum;
		c[i]=sum;
	}
	if(s<=8)
	printf("0");
	else
	{
	for(int a=0;a<=6;a++)
	{
		if(c[a]==s)
		{
		printf("%d",a+1);
		break;
	}
	}
}
	return 0;
}
