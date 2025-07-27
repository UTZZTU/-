#include <stdio.h>
int main ()
{
	double s,vc,vd,vm,t;
	int sum;
	scanf("%lf %lf %lf %lf",&s,&vc,&vd,&vm);
	sum=1;
	while(s>0.8)
	{
		t=s*1.0/(vm+vd);
		s-=t*(vc+vd);
		if(s>0.8)
		{
			sum++;
			t=s*1.0/(vc+vm);
			s-=t*(vc+vd);
			if(s>0.8)
			sum++;	
		}
		else
		break;
	}
	printf("%d",sum);
	return 0;
}
