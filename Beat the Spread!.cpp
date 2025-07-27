#include <stdio.h>
int main ()
{
	int n,s,d,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&s,&d);
		if(s<d) printf("impossible\n");
		else
		{
			a=(s+d)/2;
			b=(s-d)/2;
			if(a+b==s&&a-b==d)
			printf("%d %d\n",a,b);
			else printf("impossible\n");
		}
	}
	return 0;
}
