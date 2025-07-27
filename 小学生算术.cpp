#include <stdio.h>
int main ()
{
	int x,y,sum,k1,k2,jw;
	while(~scanf("%d%d",&x,&y))
	{
		if(x==0&&y==0)
		{
			break;
		}
		else
		{
			sum=0;
			jw=0;
			while(x!=0&&y!=0)
			{
				k1=x%10;
				k2=y%10;
				if(k1+k2+jw>=10)
				sum++;
				jw=(k1+k2+jw)/10;
				x/=10;
				y/=10;
			}
			while(x!=0)
			{
				k1=x%10;
				if(k1+jw>=10)
				sum++;
				jw=(k1+jw)/10;
				x/=10;
			}
			while(y!=0)
			{
				k2=y%10;
				if(k2+jw>=10)
				sum++;
				jw=(k2+jw)/10;
				y/=10;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}