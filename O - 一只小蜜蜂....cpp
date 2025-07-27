#include <stdio.h>
int main ()
{
	long long int n,a,b,t,s,q,r;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld",&a,&b);
		if(b-a==1)
		printf("1\n");
		else if(b-a==2)
		printf("2\n");
		else
		{
			r=b-a;
			t=1;
			q=1;
			for(int i=2;i<=r;i++)
			{
				s=t+q;
				t=q;
				q=s;
			}
			printf("%lld\n",s);
		}
	}
	return 0;
}
