#include<stdio.h>
#include <string.h>
int b[30];
void fun(int a[])
{
	int i,jw=0;
	for(i=0;i<=29;i++)
	{
		b[i]=b[i]+a[i]+jw;
		jw=b[i]/10;
		b[i]%=10;
	}
}
int main ()
{
	int a[30],n,i,j,jw;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	a[0]=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		fun(a);
		jw=0;
		for(j=0;j<=29;j++)
		{
			a[j]=a[j]*2+jw;
			jw=a[j]/10;
			a[j]%=10;
		}
	}
	for(i=29;b[i]==0;i--)
	;
	for(i;i>=0;i--)
	printf("%d",b[i]);
	return 0;
 } 
