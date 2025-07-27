#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n,k,m,sum=0,i,w,j,max,min;
	double s[10005],q;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=n;i++)
	{
		sum=0;
		max=0;
		min=100;
		for(j=1;j<=k;j++)
		{
			scanf("%d",&w);
			sum+=w;
			if(w>max)
			max=w;
			if(w<min)
			min=w;
		}
		q=(sum-max-min)*1.0/(k-2);
		s[i]=q;
	}
	sort(s+1,s+1+n);
	for(i=n-m+1;i<n;i++)
	printf("%.3f ",s[i]);
	printf("%.3f",s[i]);
	return 0;
}