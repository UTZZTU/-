#include <stdio.h>
int main ()
{
	int a,b,c,i,pd=0;
	scanf("%d%d%d",&a,&b,&c);
	if(c%b==0||c%a==0||c%(a+b)==0)
	printf("Yes");
	else
	{
		for(i=1;;i++)
	{
		c-=a;
		if(c<0)
		break;
		else
		{
			if(c%b==0||c%(a+b)==0)
			{
				pd=1;
				break;
			}
		}
	}
	if(pd==1)
	printf("Yes");
	else
	printf("No");
	}
	return 0;
}