#include <stdio.h>
int calculate (int a,int b)
{
	int temp;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return (a);
}
int main ()
{
	int t,m,x,y,z,p,min,w;
	scanf("%d",&t);
	while(t--)
	{
		min=100000000;
		int c[20],b[20];
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&c[i]);
		}
		x=c[0];
		for(int i=0;i<m;i++)
		{
			y=c[i];
			if(x<y)
			{
				z=x;
				x=y;
				y=z;
			}
			p=calculate(x,y);
			b[i]=p;
			if(p<min)
			min=p;
		}
		w=0;
		for(int i=0;i<m;i++)
		{
			if(b[i]==min)
			w++;
			else
			{
				if(b[i]%min==0)
				w++;
				else
				{
					printf("1\n");
					break;
				}
			}
		}
		if(w==m)
		printf("%d\n",min);
	}
	return 0;
}
