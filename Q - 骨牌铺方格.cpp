#include <stdio.h>
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		printf("1\n");
		else if(n==2)
		printf("2\n");
		else
		{
			long long int s,w=1,q=2;
		    for(int i=3;i<=n;i++)
		    {
		    	s=w+q;
		    	w=q;
		    	q=s;
			}
			printf("%lld\n",s);
		}
	}
	return 0;
}
