#include <stdio.h>
int main ()
{
	long long int n,m,i,sum=0,q,w;
	scanf("%lld%lld",&n,&m);
	i=1;
	q=n;
	w=m;
	q=q-i+1;
	w=w-i+1;
	i++;
	while(q>0&&w>0)
	{
		
		sum+=q*w;
		q=n;
	    w=m;
		q=q-i+1;
	    w=w-i+1;
	    i++;
	}
	printf("%lld",sum);
	return 0;
}
