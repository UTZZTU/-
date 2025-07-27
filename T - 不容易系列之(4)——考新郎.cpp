#include <stdio.h>
int fun(int a,int b)
{
	if(a>=b)
	return b;
	else  return a;
}
int main ()
{
	long long int c,n,m,s,q,w,a1,a2,t,j;
	scanf("%lld",&c);
	while(c--)
	{
		a1=0;
		a2=1;
		scanf("%lld%lld",&n,&m);
		q=1;
		w=1;
		j=fun(m,n-m);
		if(n==m)
		{
			t=1;
		}
		else
		{
			for(int i=1;i<=j;i++)
		{
			q*=n;
			n=n-1;
		}
		for(int i=2;i<=j;i++)
		{
			w*=i;
		}
		t=q/w;
		}
		if(m==1)
		printf("0\n");
		else if(m==2)
		printf("%lld\n",t);
		else
		{
			for(int i=3;i<=m;i++)
			{
				s=(i-1)*(a1+a2);
				a1=a2;
				a2=s;
			}
			printf("%lld\n",t*s);
		}
	}
	return 0;
}
