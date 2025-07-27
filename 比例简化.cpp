#include <stdio.h>
#include <string.h>
int fun(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main ()
{
	int a,b,l,i,j;
	double s[105][105],min=9999999,k1,k2;
	memset(s,-1,sizeof(s));
	scanf("%d%d%d",&a,&b,&l);
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=l;j++)
		{
			k1=i*1.0/j;
			k2=a*1.0/b;
			if(k1>=k2&&fun(i,j)==1)
			{
				s[i][j]=k1-k2;
				if(s[i][j]<min)
				min=s[i][j];
			}
		}
	}
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=l;j++)
		{
			if(s[i][j]==min)
			{
				printf("%d %d",i,j);
				break;
			}	
		}
	}
	return 0;
}