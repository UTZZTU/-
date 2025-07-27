#include <stdio.h>
#include <math.h>
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int w,q,s=0,m;
		for(int i=1;i<=30;i++)
		{
			q=pow(10,i);
			w=n%q/pow(10,i-1);
				if(w%2==0)
				{
			printf("%d",w);
			s++;
		}
			m=n/q;
			if(m==0)
				break;
		}
	
		if(s==0)
		printf("0\n");
		else	printf("\n");
	}
	return 0;
}
