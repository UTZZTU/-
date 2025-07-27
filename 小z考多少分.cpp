#include <stdio.h>
#include <math.h>
int main ()
{
    int n,m,p,ai,bi,t;
    double sum,c[400],q;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++)
    {
    	scanf("%d%d",&ai,&bi);
    	sum=ai*0.7+bi*0.3;
    	c[i]=sum;
	}
	for(int i=0;i<n-1;i++)
	{
		for(int a=0;a<n-1-i;a++)
		{
			if(c[a]<c[a+1])
			{
				t=c[a+1];
				c[a+1]=c[a];
				c[a]=t;
			}
		}
	}
	q=(c[m-1]-p*0.3)/0.7;
	int e;
	e=ceil(q);
	if(e<0)
	printf("0");
	else
	printf("%d",e);
	return 0;
}
