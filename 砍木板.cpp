#include <stdio.h>
int cnt=0;
void comb(int a[],int m,int k,int s)
{
	int i,j,t;
	for(i=m;i>=k;i--)
	{
		a[k]=i;
		if(k>1)
		comb(a,i-1,k-1,s);
		else
		{
			for(t=0,j=a[0];j>0;j--)
			{
				t+=a[j];
			}
			if(t==s)
			{
				cnt=1;
				break;
			}
		}
	}
}
int main ()
{
	int g,l,k,i,a[2000],s;
	scanf("%d",&g);
	for(i=1;i<=g;i++)
	{
		cnt=0;
		scanf("%d %d",&l,&k);
		if(l==1&&k==1)
		printf("possible");
		else if(l<=k)
		printf("impossible");
		else
		{
			a[0]=k;
			s=l;
		comb(a,l,k,s);
		if(cnt==1)
		printf("possible");
		else
		printf("impossible");
		}
		if(i!=g)
		printf("\n");
	}
}
