#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(n%k==0)
		{
			int dd=n/k;
			int a=n/2;
			int b=n-a;
			if(a%dd==0&&b%dd==0) puts("Yes");
			else puts("No");
		}
		else
		{
			int cnta=n%k;
			int cntb=k-cnta;
			int dd1=n/k+1,dd2=n/k,c=n/2;
			int x,y;
			int gcds=exgcd(dd1,dd2,x,y);
			c/=gcds,dd1/=gcds,dd2/=gcds;
			int k1_max=floor(1.0L*(cnta-x*c)/(1.0L*(dd2)));
			int k1_min=ceil(1.0L*(0-x*c)/(1.0L*(dd2)));
			int k2_max=floor(1.0L*(y*c)/(1.0L*(dd1)));
			int k2_min=ceil(1.0L*(y*c-cntb)/(1.0L*(dd1)));
			if(k1_min>k2_max||k2_min>k1_max) puts("No");
			else
			{
				if(min(k1_max,k2_max)>=max(k1_min,k2_min)) puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}