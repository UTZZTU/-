#include <stdio.h>
int max,min;
void hef(int a,int b)
{
	int s,m;
	if(a>=b)
	s=b;
	else s=a;
	for(int i=1;i<=s;i++)
	{
		if(a%i==0&&b%i==0)
		m=i;
	}
	max=m;
}
void led(int a,int b)
{
	int s,m;
	if(a>=b)
	s=a;
	else s=b;
	for(int i=s;i>1;i++)
	{
		if(i%a==0&&i%b==0)
		{
			m=i;
			break;
		}
	}
	min=m;
}
int main ()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		hef(a,b);
		led(a,b);
		printf("%d %d\n",max,min);
	}
	return 0;
}
