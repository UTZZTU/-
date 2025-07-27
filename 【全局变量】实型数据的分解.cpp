#include <stdio.h>
int main ()
{
	int a[14];
	a[1]=2;a[2]=7;a[3]=5;a[4]=30;a[5]=169;a[6]=441;a[7]=1872;a[8]=7632;
	a[9]=1740;a[10]=93313;a[11]=459901;a[12]=1358657;a[13]=2504881;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			printf("%d\n",a[n]);
		}
	}
	return 0;
}
 
