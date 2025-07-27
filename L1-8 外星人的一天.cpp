#include <stdio.h>
int main ()
{
	int n,d,h,x,i,s,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d:%d",&d,&h,&x);
		if(d==0)
		printf("%d %02d:%02d\n",d,h,x);
		else
		{
			s=(d-1)*24*60+h*60+x;
			s/=2;
			d=s/60/24;
			d++;
			s%=24*60;
			h=s/60;
			x=s%60;
			printf("%d %02d:%02d\n",d,h,x);
		}
	}
	return 0;
}