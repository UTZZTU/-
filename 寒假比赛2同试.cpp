#include <stdio.h>
int a[5000][5000];
int main ()
{
	int i,j,jd,shu,h,l,pd=0;
	scanf("%d",&jd);
	if(jd==1)
	{
		scanf("%d",&shu);
		if(shu==1)
		printf("1 1");
		else
		{
			a[0][0]=1;
	for(i=1;i<5000;i++)
	{
		a[i][0]=a[i-1][0]+i+1;	
		if(a[i][0]==shu)
		{
			printf("%d 1",i+1);
			pd=1;
			break;
		}
	}
	if(pd==0)
	{
		for(i=0;i<4999;i++)
	{
		for(j=1;j<5000-i;j++)
		{
			a[i][j]=a[i][j-1]+j+i;
			if(a[i][j]==shu)
			{
				printf("%d %d",i+1,j+1);
				break;
			}
		}
	}
	}
		}
		
	}
	else if(jd==2)
	{
		scanf("%d%d",&h,&l);
		if(h==1&&l==1)
		{
			printf("1");
		}
		else
		{
			a[0][0]=1;
	for(i=1;i<5000;i++)
	{
		a[i][0]=a[i-1][0]+i+1;
		if(h==i+1&&l==1)
		{
			printf("%d",a[i][0]);
			pd=1;
			break;
			}	
	}
	if(pd==0)
	{
		for(i=0;i<4999;i++)
	{
		for(j=1;j<5000-i;j++)
		{
			a[i][j]=a[i][j-1]+j+i;
			if(h==i+1&&l==j+1)
			{
				printf("%d",a[i][j]);
				break;
			}
		}
	}
	}
		}
	}
return 0;
}
