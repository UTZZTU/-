#include <stdio.h>
#include <string.h>
int main ()
{
	int l1,l2,a[1010],b[1010],i,sum1=0,sum2=0,k1=0,k2=0;
	char x[1010],y[1010];
	scanf("%s",x);
	scanf("%s",y);
	l1=strlen(x);
	l2=strlen(y);
	for(i=0;i<l1;i++)
	{
		if(x[i]-'0'<y[i]-'0')
		{
			x[i]=-1+'0';
			sum1++;
		}
		else if(x[i]-'0'>y[i]-'0')
		{
			y[i]=-1+'0';
			sum2++;
		}
	}
	if(sum1==l1)
	{
		printf("BOOM\n");
	}
	else
	{
		for(i=0;i<l1;i++)
		{
			if(x[i]-'0'!=-1)
			{
				a[k1]=x[i]-'0';
				k1++;
			}
		}
		for(i=0;a[i]==0&&i<k1-1;i++)
		;
		for(i;i<k1;i++)
		printf("%d",a[i]);
		printf("\n");
	}
	if(sum2==l2)
	{
		printf("BOOM");
	}
	else
	{
		for(i=0;i<l2;i++)
		{
			if(y[i]-'0'!=-1)
			{
				b[k2]=y[i]-'0';
				k2++;
			}
		}
		for(i=0;b[i]==0&&i<k2-1;i++)
		;
		for(i;i<k2;i++)
		printf("%d",b[i]);
	}
	return 0;
}
