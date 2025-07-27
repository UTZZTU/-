#include <stdio.h>
int main ()
{
	int p,e,i,d,j;
	scanf("%d%d%d%d",&p,&e,&i,&d);
	for(j=d+1;j<=21252+d;j++)
	{
		if((j-p)>=0&&(j-p)%23==0&&(j-e)>=0&&(j-e)%28==0&&(j-i)>=0&&(j-i)%33==0)
		{
			break;
		}
	}
	printf("%d",j-d);
	return 0;
}
