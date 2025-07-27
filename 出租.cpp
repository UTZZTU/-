#include <stdio.h>
#include <string.h>
typedef long long ll;
int main ()
{
	ll n,s;
	int a[10],b[11],k=11,c[10],i=0,j,m;
	memset(a,0,sizeof(a));
	scanf("%lld",&n);
	s=n;
	while(k--)
	{
		a[s%10]=1;
		s/=10;
	}
	j=9;
	for(j;j>=0;j--)
	{
		if(a[j]==1)
		{
			c[i]=j;
			i++;
		}
	}
	s=n;
	k=10;
	while(k>=0)
	{
		for(m=0;m<i;m++)
		{
			if(c[m]==s%10)
			{
				b[k]=m;
				k--;
				s/=10;
				break;
			}
		}
	}
	printf("int[] arr = new int[]{");
	for(m=0;m<i-1;m++)
	printf("%d,",c[m]);
	printf("%d};",c[m]);
	printf("\n");
	printf("int[] index = new int[]{");
	for(m=0;m<10;m++)
	printf("%d,",b[m]);
	printf("%d};",b[m]);
	return 0;
}