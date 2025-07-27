#include <stdio.h>
struct fushu
{
	double s1,s2,x1,x2;
	char f;
};
int main ()
{
	struct fushu w;
	int i,n;
	double sum1,sum2;
	char s,k,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		getchar();
		scanf("%c%lf%lfi%c%c%c%lf%lfi%c",&k,&w.s1,&w.x1,&k,&w.f,&k,&w.s2,&w.x2,&k);
		if(w.f=='+')
		{
			sum1=w.s1+w.s2;
			sum2=w.x1+w.x2;
		}
		else
		{
			sum1=w.s1-w.s2;
			sum2=w.x1-w.x2;
		}
		if(sum2>0)
		printf("%.2f+%.2fi",sum1,sum2);
		else
		printf("%.2f%.2fi",sum1,sum2);
		if(i!=n)
		printf("\n");
	}
	return 0;
}
