#include <stdio.h>
int main ()
{
	long long int y,a1,a2,a3,a4,a5,t,q;
	scanf("%lld",&y);
	int c[13];
	c[0]=0;c[1]=31;c[2]=28;c[3]=31;c[4]=30;c[5]=31;c[6]=30;
	c[7]=31;c[8]=31;c[9]=30;c[10]=31;c[11]=30;c[12]=31;
	while(y--)
	{
		q=0;
		scanf("%lld%lld%lld%lld%lld",&a1,&a2,&a3,&a4,&a5);
		if(a4==a1)
		{
			t=a5-a2;
			for(int i=1;i<=t;i++)
			{
				a3*=2;
			}
		}
		else
		{
			for(int i=a1+1;i<a4;i++)
			{
				q+=c[i];
			}
			t=q+c[a1]-a2+a5;
			for(int i=1;i<=t;i++)
			{
				a3*=2;
			}
		}
		printf("%lld\n",a3);
		
	}
	return 0;
}
