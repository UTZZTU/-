#include <stdio.h>
int main ()
{
	int t,n,x,y,i,j,a,sum,jd;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum=0;
		scanf("%d %d %d",&n,&x,&y);
		if(n==2)
		printf("%d %d",x,y);
		else
		{
			if((y-x)%(n-1)==0)
			{
				jd=(y-x)/(n-1);
				for(j=1;j<n;j++)
				{
					printf("%d ",x);
					x+=jd;
				}
				printf("%d",y);
			}
			else
			{
				for(a=1;a<=y-x;a++)
				{
					if((y-x)%a==0)
					{
						if((y-x)/a+1<n)
						{
							break;
						}
					}
				}
				while(x>0&&sum<n-1)
				{
					sum++;
					x-=a;
				}
				x+=a;
				for(j=1;j<n;j++)
				{
					printf("%d ",x);
					x+=a;
				}
				printf("%d",x);
			}
		}
		if(i!=t)
		printf("\n");
	}
	return 0;
}
