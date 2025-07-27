#include <stdio.h>
#include <math.h>
int main ()
{
	int t,a,b,n1,n2,a1,a2,a3,a4;
	char e,f,g;
	scanf("%d",&t);

	while(t--)
	{	getchar();
		scanf("%c%d%c%c%d",&e,&a,&f,&g,&b);
		n1=abs(e-g);
		n2=abs(a-b);
		if(n1==0&&n2!=0)
		{
			a1=n2;
		  	a2=1;
		  	a3=1;
		  if((n2+1)%2==1)
		  {
		  	a4=2;
		  	printf("%d %d %d %d\n",a1,a2,a3,a4);
		  }
		  else
		  {
		  	printf("%d %d %d Inf\n",a1,a2,a3);
		  }
		}
		else if(n1!=0&&n2==0)
		{
			a1=n1;
		  	a2=1;
		  	a3=1;
		  	if((n1+1)%2==1)
		  {
		  	a4=2;
		  	printf("%d %d %d %d\n",a1,a2,a3,a4);
		  }
		  else
		  {
		  	printf("%d %d %d Inf\n",a1,a2,a3);
		  }
		}
		else if(n1==0&&n2==0)
		{
			printf("0 0 0 0\n");
		}
		else
		{
			if(n1==n2)
			{
				a1=n1;
				a2=1;
				a3=2;
				a4=1;
				printf("%d %d %d %d\n",a1,a2,a3,a4);
			}
			else
			{
				if(n1>n2)
				{
					a1=n1;
					a2=2;
					a3=2;
					if(n1%2==0&&n2%2==0||n1%2==1&&n2%2==1)
					{
						if(n2>=2)
						a4=3;
						else
						a4=n1;
						printf("%d %d %d %d\n",a1,a2,a3,a4);
					}
					else
					{
						printf("%d %d %d Inf\n",a1,a2,a3);
					}
				}
				else
				{
					a1=n2;
					a2=2;
					a3=2;
					if(n1%2==0&&n2%2==0||n1%2==1&&n2%2==1)
					{
						if(n1>=2)
						a4=3;
						else
						a4=n2;
						printf("%d %d %d %d\n",a1,a2,a3,a4);
					}
					else
					{
						printf("%d %d %d Inf\n",a1,a2,a3);
					}
				}
			}
		}
	}
	return 0;
}
