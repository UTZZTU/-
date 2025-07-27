#include <stdio.h>
#include <math.h>
int main ()
{
	long long int a,b;
	while (scanf("%lld %lld",&a,&b)!=EOF)
	{
		long long int s,w,sum=0,k=0,u;
		if(a==0&&b==0)
		break;
		else
		{
			for(int i=0;i<=10;i++)
			{
				u=1;
				for(int c=1;c<=i+1;c++)
				{
					u*=10;
				}
				w=b%u/(1*pow(10,i));
				s=a%u/(1*pow(10,i));
				if(w==0||s==0)
				{
					if(w+k>=10||s+k>=10)
					{
						sum++;
					}
					break;
				}
				if(w+s+k>=10)
				{
					sum++;
					k++;
				}
				
			}
			if(sum==0)
			printf("No carry operation.\n");
			else if(sum==1)
			printf("1 carry operation.\n");
			else printf("%d carry operations.\n",sum);
		}
	}
	return 0;
}
