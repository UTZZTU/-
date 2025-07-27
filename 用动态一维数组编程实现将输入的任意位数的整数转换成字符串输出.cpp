#include <stdio.h>
#include <stdlib.h>
int main ()
{
	long long int n,sum=0,q,i;
	char *p;
	scanf("%lld",&n);
	q=n;
	if(n==0)
	printf("0");
	else
	{
		while(q!=0)
	{
		q=q/10;
		sum++;
	 } 
	p=(char*)calloc(sum,sizeof(char));
	while(n!=0)
	{
		*p=n%10+'0';
		n/=10;
		p++;
	 } 
	p--;
	for(i=0;i<sum;i++)
	{
		printf("%c",*p);
		p--;
	}
	}
	return 0;
}
