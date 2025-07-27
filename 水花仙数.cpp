#include <stdio.h>
int main ()
{
	int m,n;
	while (scanf("%d %d",&m,&n)!=EOF)
	{
		int s=0;
		if(m==n)
		{
			if(m==(m/100)*(m/100)*(m/100)+(m%100/10)*(m%100/10)*(m%100/10)+(m%100%10)*(m%100%10)*(m%100%10)) 
			printf("%d\n",m);
			else printf("no\n");
		}
		else if (m<n)
		{
		int c=m;
		for(int i=m;i<=n;i++)
		{
			if(i==(i/100)*(i/100)*(i/100)+(i%100/10)*(i%100/10)*(i%100/10)+(i%100%10)*(i%100%10)*(i%100%10))
		    {
			s++;
			printf("%d ",i);
		}
		    else  c++;
			if(c==n)  printf("no\n");
	    }if (s>0)
	    printf("\n");
	   
		}
		else 
		{
				int c=n;
		for(int i=n;i<=m;i++)
		{
			if(i==(i/100)*(i/100)*(i/100)+(i%100/10)*(i%100/10)*(i%100/10)+(i%100%10)*(i%100%10)*(i%100%10))
			{
			s++;
			printf("%d ",i);
		}
			else  c++;
			if(c==m)  printf("no\n");
	    }if (s>0)
	    printf("\n");
		}
	}
	return 0;
}
