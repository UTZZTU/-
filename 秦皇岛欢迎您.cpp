#include <stdio.h>
int main ()
{
int T;
scanf("%d",&T);
while(T--)
{
	int r,b,s=1,e,f;
	scanf("%d %d",&r,&b);
		if(r<2)
		{
			printf("Case #%d: 0/1\n",s);
		}
		else
		{
			e=r*(r-1)/2;
			f=(r+b)*(r+b-1)/2;
			for(int i=2;i<=e;i++)
			{
				while(e%i==0&&f%i==0)
				{
					e=e/i;
					f=f/i;
				}
			}
		if(e==f)
		{
				printf("Case #%d: 1/1\n",s);
		}
		else 
		{
				printf("Case #%d: %d/%d\n",s,e,f);
		}
		}
		s++;
	
}
return 0;
	
}
