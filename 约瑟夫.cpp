#include <stdio.h>
int main ()
{
	int k;
	while(scanf("%d",&k)!=EOF)
	{
		if(k==0)
		break;
		else
		{
			long long int c[28],m=k;
		   while(1)
			{
				for(int a=0;a<2*k;a++)
			{
				c[a]=1;
			}
			m++;
			    int i=-1,pm=0,cn=0,w=0,s=0;
				while(cn<k)
			{
				i=i+1;
				if(i==2*k)
				i=0;
				if(c[i]!=0)
				{
					pm++;
					if(pm==m)
					{
						c[i]=0;
						cn++;
						pm=0;
						if(i>=k)
						w++;
						else  
						{
							s++;
							break;
						}
					}
				}
			}
			if(s==1)
			continue;
			if(w==k)
			{
				printf("%lld\n",m);
				break;
			}
			}
		}
		}
	return 0;
}
