#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	int n,i,w[10],q,j,t;
	while(scanf("%d",&n)!=EOF)
	{
		
		for(i=n+1;;i++)
		{
			memset(w,0,sizeof(w));
			q=i;
			t=0;
			while(q!=0)
			{
				w[q%10]++;
				q/=10;
			}
			for(j=0;j<10;j++)
			{
				if(w[j]>=2)
				break;
				else
				t++;
			}
			if(t==10)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
