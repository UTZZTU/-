#include <stdio.h>
int main ()
{
	int a,b,i,t;
	double s1,s2,sum;
	while(~scanf("%d%d",&a,&b))
	{
		if(a==0||b==0)
		break;
		else
		{
			t=0;
			sum=0;
			s1=1.0/a;
			s2=1.0/b;
			for(i=1;;i++)
			{
				if(sum+s1+s2<1)
				{
					sum+=s1+s2;
					t+=2;
				}
				else
				{
					sum+=s1;
					t+=1;
					if(sum>=1)
					break;
					else
					{
						t++;
						break;
					}
				}
			}
			printf("%d\n",t);
		}
	}
	return 0;
}
