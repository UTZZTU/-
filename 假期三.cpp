#include <stdio.h>
#include <math.h>
int main ()
{
    int l1,a1,l2,a2,i;
    scanf("%d%d%d%d",&l1,&a1,&l2,&a2);
    for(i=1;;i++)
    {
    	l1-=a2;
    	if(l1<=0)
    	{
    		printf("%d",i);
    		break;
		}
		l2-=a1;
		if(l2<=0)
		{
			printf("Sorry,Miss Moonlight");
			break;
		}
	}
	return 0;
}
