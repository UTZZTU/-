#include <stdio.h>
#include <math.h>
int main ()
{
int a,b;
while(scanf("%d %d",&a,&b)!=EOF)
{
	int w=0,s;
	if(a>=b)
	{
		for(int i=b;i<=a;i++)
		{
			int q=sqrt(i);
			s=0;
			for(int c=2;c<=q;c++)
			{
				if(i%c==0)
				{
					s++;
					break;
				}
			}
			if(s==0)
			w++;
		}
		printf("%d\n",w);
	}
	else
	{
		for(int i=a;i<=b;i++)
		{
			int q=sqrt(i);
			s=0;
			for(int c=2;c<=q;c++)
			{
				if(i%c==0)
				{
				s++;
				break;	
				}
				
			}
			if(s==0)
			w++;
		}
		printf("%d\n",w);
	}
}
	return 0;
}
