#include <stdio.h>
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			int s;
			do
			{
				s=0;
				while(n!=0)
				{
					s+=n%10;
					n=n/10;
				}
				n=s;
			}while(n>=10);
			printf("%d\n",s);
		}
	}
	return 0;
}
