#include <stdio.h>
#include <string.h>
int main ()
{
	int a[1005],num,rs=0,cs=0,n,sj=0,xs,fz,q1,q2;
	char s;
	scanf("%d",&n);
	for(int i=0;i<n;)
	{
		rs=0;
			sj=0;
			memset(a,0,sizeof(a));
		for(;scanf("%d %c %d:%d",&num,&s,&xs,&fz)&&num!=0;)
	{
			if(s=='S')
			{
				a[num]=xs*100+fz+1;
			}
			else if(s=='E')
			{
				if(a[num]!=0)
				{
					rs++;
					a[num]-=1;
					q1=a[num]/100;
					q2=a[num]%100;
					if(q2>fz)
					sj+=(xs-1-q1)*60+fz+60-q2;
					else
					sj+=(xs-q1)*60+fz-q2;
					a[num]=0;
				}
			}
	}
	i++;
	if(sj==0)
	printf("0 0\n");
	else
	{	
		printf("%d %d\n",rs,(int)(1.0*sj/rs+0.5));
	}
	}
	return 0;
}