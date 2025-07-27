#include <stdio.h>
int main ()
{
	int m,n,i,j,a1,a2,a3;
	scanf("%d%d",&m,&n);
	for(i=0;i<=n;i++)
	{
		a1=i;
		if(3*m-n-14*a1>=0&&(3*m-n-14*a1)%8==0)
		{
			a2=(3*m-n-14*a1)/8;
			a3=n-a1-a2;
			printf("%d %d %d\n",a1,a2,a3);
		}
	}
	return 0;
}
