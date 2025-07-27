#include <stdio.h>
int main ()
{
	int n,i,a=0,b=0,c=0,sum=0,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k%3==0)
		a++;
		else if(k%3==1)
		b++;
		else
		c++;
	}
	sum+=a/2;
	if(b<=c)
	sum+=b;
	else
	sum+=c;
	printf("%d",sum);
	return 0;
}