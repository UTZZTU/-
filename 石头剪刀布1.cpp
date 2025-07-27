#include <stdio.h>
int main ()
{
	int i,a=0,b=0,k1,k2;
	for(i=1;i<=5;i++)
	{
		scanf("%d %d",&k1,&k2);
		if(k1!=k2)
		{
			if(k1==0&&k2==1)
			a++;
			else if(k1==0&&k2==2)
			b++;
			else if(k1==1&&k2==0)
			b++;
			else if(k1==1&&k2==2)
			a++;
			else if(k1==2&&k2==1)
			b++;
			else
			a++;
		}
	}
	if(a>b)
	printf("A");
	else if(a<b)
	printf("B");
	else
	printf("D");
	return 0;
}