#include <stdio.h>
#include <math.h>
int main ()
{
	int a=0,b=0,c=0,d=0,i,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k>=90)
		a++;
		else if(k<60)
		d++;
		else if(k>=80&&k<=89)
		b++;
		else if(k>=60&&k<=79)
		c++;
	}
	printf("%d\n%d\n%d\n%d",a,b,c,d);
	return 0;
}