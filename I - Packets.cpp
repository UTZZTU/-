#include <stdio.h>
#include <math.h>
int main ()
{
	int c[6],s,sum,r;
	while(scanf("%d",&c[0])!=EOF)
	{
		s=0;
		sum=0;
		if(c[0]==0)
		s++;
		for(int i=1;i<6;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]==0)
			s++;
		}
		if(s==6)
		break;
		else
		{
		    sum+=c[5]+c[4]+c[3]+(c[2]+3)/4;
		    if(c[2]%4==1)
		    r=5;
		    else if(c[2]%4==2)
		    r=3;
		    else if(c[2]%4==3)
		    r=1;
		    else r=0;
		    if(c[1]>(5*c[3]+r))
		    {
		    	sum+=((c[1]-5*c[3]-r)+8)/9;
			}
			if(c[0]>(36*sum-36*c[5]-25*c[4]-16*c[3]-9*c[2]-4*c[1]))
			{
				sum+=((c[0]-(36*sum-36*c[5]-25*c[4]-16*c[3]-9*c[2]-4*c[1]))+35)/36;
			}
			 printf("%d\n",sum);
		}
	}
	return 0;
}
