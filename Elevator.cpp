#include <stdio.h>
int main ()
{
	int n,t,w,s;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			w=0;
			s=0;
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&t);
				if(t>w)
				{
					s+=(t-w)*6+5;
					w=t;
				}
				else
				{
					s+=(w-t)*4+5;
					w=t;
				}
			}
			printf("%d\n",s);
		}
	}
	return 0;
}
