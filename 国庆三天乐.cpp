#include <stdio.h>

int main()
{
	int T ,i=1;
	scanf("%d",&T);
	while(i<=T)
		{
		int a,b;
		double c,d,e,f,g;
		scanf("%d %d %lf %lf %lf",&a,&b,&c,&d,&e);
			
		    i=i+1;
			f=(a*(1+c/100*b/365))*(1+e/100);
			g=a*(1+d/100/365*(365+b));
	printf("%.1f\n",f);
		printf("%.1f\n",g);
	
		}
		
		
		
    
    return 0;
}
