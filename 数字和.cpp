#include <stdio.h>
#include <math.h>
int main ()
{
	long long int t,n,s,i,a[100],m,k,sum1,sum2,j,tp,q;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum1=0;
		tp=0;
		sum2=0;
		scanf("%lld %lld",&n,&s);
		m=0;
		k=n;
		while(k!=0)
		{
			a[m]=k%10;
			k/=10;
			tp+=a[m];
			m++;
		}
		if(tp<=s)
		printf("0");
		else
		{
			for(j=m-1;j>=0;j--)
			{
				sum1+=a[j];
				if(sum1>s)
				break;
			}
			while(sum1-a[j]+1>s)
			{
				sum1-=a[j];
				j++;
			}
			if(j==m-1)
			{
				sum2=pow(10,m);
				printf("%lld",sum2-n);
			}
			else
			{
				j++;
				a[j]+=1;
				for(q=j;q<=m-1;q++)
				{
					sum2+=a[q]*pow(10,q);
				}
				printf("%lld",sum2-n);
			}
		}
		if(i!=t)
		printf("\n");
	}
	return 0;
}
