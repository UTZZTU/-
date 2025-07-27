#include <stdio.h>
int main ()
{
	char s[100];
	int i,sum,c[32];
	while(gets(s)!=NULL)
	{
		sum=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				sum=sum*10+(s[i]-'0');
			}
		}
		printf("%d ",sum);
		i=0;
	    while(sum!=0)
	    {
	    	c[i]=sum%2;
	    	sum/=2;
	    	i++;
		}
		for(i=i-1;i>=0;i--)
		{
			printf("%d",c[i]);
		}
		printf("\n");
	}
	return 0;
}
