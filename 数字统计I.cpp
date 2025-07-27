#include <stdio.h>
int main ()
{
	int l,r,i,k,sum=0,s,t;
	scanf("%d%d",&l,&r);
	for(i=l;i<=r;i++)
	{
		s=0;
		k=i;
		while(k!=0)
		{
			t=k%10;
			if(t==2)
			s++;
			k/=10;
		}
		sum+=s;
	}
	printf("%d",sum);
	return 0;
}