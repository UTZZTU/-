#include <stdio.h>
int main ()
{
	int n,i=0,a[1000],b[1000],k,c1=0,c2=0,m=0;
	scanf("%d",&n);
	k=n*n;
	while(n!=0)
	{
		a[c1]=n%10;
		n/=10;
		c1++;
	}
	while(k!=0)
	{
		b[c2]=k%10;
		k/=10;
		c2++;
	}
	while(a[i]==b[i]&&i<c1)
	{
		m++;
		i++;
	}
	if(m==c1)
	printf("Yes");
	else
	printf("No");
	return 0;
}
