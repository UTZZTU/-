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
		int c[20],max=-9999999,k;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]>max)
			{
					max=c[i];
					k=i;
			}
		
		}
		printf("%d %d\n",max,k);
	}
}
	return 0;
}
