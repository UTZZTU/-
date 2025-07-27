#include <stdio.h>
struct stu
{
	int a,b,c;
}s[1005];
int main ()
{
	int n,i,j,sum=0,fx1,fx2,fx3;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			fx1=s[i].a-s[j].a;
			fx2=s[i].b-s[j].b;
			fx3=s[i].c-s[j].c;
			if(fx1<=5&&fx1>=-5&&fx2<=5&&fx2>=-5&&fx3<=5&&fx3>=-5&&(fx1+fx2+fx3)<=10&&(fx1+fx2+fx3)>=-10)
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}