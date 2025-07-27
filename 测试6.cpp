#include <stdio.h>
int main ()
{
	int n;
	int g=0;
	scanf("%d",&n);
	for(int e=1;e<=66;e++)
				{
					n/=2;
					g++;
					if(n%2!=0)
						break;
				}
	printf("%d",g);
		
	return 0;
}
