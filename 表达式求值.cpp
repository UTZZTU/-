#include <stdio.h>
long long a[1000100];
char s[1000100],w[2000200];
int main ()
{
	long long int i,num=0,sum1=1,sum2=1,sum=0;
	scanf("%s",w);
	for(i=0;w[i]!='\0';i++)
	{
		num=0;
		if(w[i]=='+'||w[i]=='*')
		{
			s[sum2]=w[i];
			sum2++;
		}
		else
		{
			while(w[i]>='0'&&w[i]<='9')
		{
			num=num*10+w[i]-'0';
			num%=10000;
			i++;
		}
		i--;
		a[sum1]=num;
		sum1++;
		}
	}
	s[sum2]='\0';
	for(i=1;s[i]!='\0';i++)
	{
		if(s[i]=='*')
		{
			a[i+1]*=a[i];
			a[i+1]%=10000;
			a[i]=0;
		}
	}
	for(i=1;i<sum1;i++)
	{
		sum+=a[i];
	sum%=10000;
	}
	printf("%lld",sum);
	return 0;
}