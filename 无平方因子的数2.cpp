#include <stdio.h>
int main ()
{
	 long long int n,m;
	while (scanf("%lld %lld",&n,&m)!=EOF)
	{
		long long int w,s=0;
		for(long long int i=n;i<=m;i++)
		{
			w=0;
			for(long long int a=1;a<=i;a++)
			{
				if(i%(a*a)==0)
				{
				w++;
			}
			}
			if(w==1)
			{
			s++;
		    }
		    
		}
		printf("%lld\n",s);
	}
	return 0;
}
