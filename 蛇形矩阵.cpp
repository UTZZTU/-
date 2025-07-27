#include <stdio.h>
int fun(int a,int b)
{
	if(a>=b)
	return b;
	else
	return a;
}
int main ()
{
	int n,k,i,j,sum=1,l;
	scanf("%d%d",&n,&k);
	i=1;
	j=1;
	while(sum<k)
	{
		if(j<n)
		{
			j++;
			sum++;
		}
		else
		{
			i++;
			sum++;
		}
		if(sum==k)
		break;
		else
		{
			l=fun(j-1,n-i);
			if(sum+l<k)
			{
				j-=l;
				i+=l;
				sum+=l;
				if(i<n)
				{
					i++;
					sum++;
				}
				else
				{
					j++;
					sum++;
				}
				if(sum==k)
				break;
				else
				{
					l=fun(i-1,n-j);
					if(sum+l<k)
					{
						j+=l;
						i-=l;
						sum+=l;
					}
					else
					{					
					    j+=k-sum;
						i-=k-sum;
						sum=k;
						break;
					}
				}
			}
			else
			{
				j-=k-sum;
				i+=k-sum;
				sum=k;
				break;
			}
		}
	}
	printf("%d %d",i,j);
	return 0;
}
