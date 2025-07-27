#include <stdio.h>
#include <string.h>
int main ()
{
	int n,i,j,a[12],q,sum=0,l,r,m;
	char z[3][40],y[3][40],h[3][40];
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%s %s %s",z[j],y[j],h[j]);
			getchar();
		}
		for(j=0;j<12;j++)
		{
			sum=0;
			memset(a,0,sizeof(a));
			a[j]=1;
			for(q=0;q<3;q++)
			{
				l=0;
				r=0;
				for(m=0;m<4;m++)
				{
					l+=a[z[q][m]-'A'];
					r+=a[y[q][m]-'A'];
				}
				if(strcmp(h[q],"even")==0)
				{
					if(l==r)
					sum++;
				}
				else if(strcmp(h[q],"up")==0)
				{
					if(l>r)
					sum++;
				}
				else if(strcmp(h[q],"down")==0)
				{
					if(l<r)
					sum++;
				}
			}
			if(sum==3)
			break;
			else
			{
				sum=0;
				a[j]=-1;
				for(q=0;q<3;q++)
			{
				l=0;
				r=0;
				for(m=0;m<4;m++)
				{
					l+=a[z[q][m]-'A'];
					r+=a[y[q][m]-'A'];
				}
				if(strcmp(h[q],"even")==0)
				{
					if(l==r)
					sum++;
				}
				else if(strcmp(h[q],"up")==0)
				{
					if(l>r)
					sum++;
				}
				else if(strcmp(h[q],"down")==0)
				{
					if(l<r)
					sum++;
				}
			}
			if(sum==3)
			break;
			}
		}
		for(j=0;j<12;j++)
		{
			if(a[j]==1)
			{
				printf("%c is the counterfeit coin and it is heavy. ",j+'A');
				break;
			}
			if(a[j]==-1)
			{
				printf("%c is the counterfeit coin and it is light. ",j+'A');
				break;
			}
		}
		if(i!=n)
		printf("\n");
	}
	return 0;
}
