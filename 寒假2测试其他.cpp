#include <stdio.h>
#include <math.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main ()
{
    long long int t,a,b,x,y,n,i,j;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&n);
    	if(a==b)
    	{
    		if(a-x==b-y)
    		{
    			if(n>2*(a-x))
    			{
    				printf("%lld",x*y);
				}
				else if(n>=a-x&&n<=2*(a-x))
				{
					printf("%lld",x*((2*(a-x)-n)+y));
				}
				else
				{
					printf("%lld",(a-n)*b);
				}
			}
			else if(a-x>b-y)
			{
				if(n>(a+b-x-y))
				{
					printf("%lld",x*y);
				}
				else if(n>=a-x&&n<=(a+b-x-y))
				{
					printf("%lld",x*(a+b-x-n));
				}
				else if(n<a-x)
				{
					printf("%lld",(a-n)*b);
				}
			}
			else 
			{
				if(n>(a+b-x-y))
				{
					printf("%lld",x*y);
				}
				else if(n>=b-y&&n<=(a+b-x-y))
				{
					printf("%lld",y*(a+b-y-n));
				}
				else if(n<b-y)
				{
				  printf("%lld",(b-n)*a);
				}
			}
		}
		else if(a>b)
		{
			if(n>(a+b-x-y))
				{
					printf("%lld",x*y);
				}
		    else if(n<b-y)
		    {
		    	printf("%lld",a*(b-n));
			}
			else if(n>=b-y&&n<=(a+b-x-y))
			{
				if(n>=a-x)
				{
					if((a+b-y-n)*y<=x*(a+b-x-n))
					printf("%lld",(a+b-y-n)*y);
					else
					printf("%lld",x*(a+b-x-n));
				}
				else
				{
					if((a-n)*b<=y*(a+b-y-n))
					printf("%lld",(a-n)*b);
					else
					printf("%lld",y*(a+b-y-n));
				}
			}	
		}
		else
		{
			if(n>(a+b-x-y))
				{
					printf("%lld",x*y);
				}
		    else if(n<a-x)
		    {
		    	printf("%lld",b*(a-n));
			}
			else if(n>=a-x&&n<=(a+b-x-y))
			{
				if(n>=b-y)
				{
					if((a+b-x-n)*x<=y*(a+b-y-n))
					printf("%lld",(a+b-x-n)*x);
					else
					printf("%lld",y*(a+b-y-n));
				}
				else
				{
					if((b-n)*a<=x*(a+b-x-n))
					printf("%lld",(b-n)*a);
					else
					printf("%lld",x*(a+b-x-n));
				}
			}	
		}
		if(i!=t)
		printf("\n");
	}
	return 0;
}
