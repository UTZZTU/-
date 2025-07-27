#include<stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct q
{
	int num1,num2;
	char s;
}a[5050];
bool cmp(q a,q b)
{
	return a.num1==b.num1?a.num2<b.num2:a.num1>b.num1;
}
int main ()
{
	int n,c,d,i,s1,s2,k=0,j,sum=0;
	char s;
	scanf("%d%d%d",&n,&c,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %c",&a[i].num1,&a[i].num2,&a[i].s);
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			 if(a[i].s=='C'&&a[j].s=='C')
			{
				if(a[i].num2+a[j].num2<=c)
				{
			    	sum=max(sum,a[i].num1+a[j].num1);
		    	}	
			}
			else if(a[i].s=='D'&&a[j].s=='D')
			{
		    	if(a[i].num2+a[j].num2<=d)
		    	{
		    		sum=max(sum,a[i].num1+a[j].num1);
		    	}
			}
			else if(a[i].s=='C'&&a[j].s=='D')
			{
				if(a[i].num2<=c&&a[j].num2<=d)
				{
					sum=max(sum,a[i].num1+a[j].num1);
				}
			}
			else if(a[i].s=='D'&&a[j].s=='C')
			{
				if(a[i].num2<=d&&a[j].num2<=c)
				{
					sum=max(sum,a[i].num1+a[j].num1);
				}
			}                                                                                                       
		}
	}
	printf("%d",sum);
	return 0;
}