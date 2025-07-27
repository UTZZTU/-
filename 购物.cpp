#include <stdio.h>
#include <algorithm>
struct gw
{
	int price;
	int value;
	double xjb;
}s[100010];
bool cmp(gw a,gw b)
{
	if(a.xjb>b.xjb)
	return true;
	else if(a.xjb<b.xjb)
	return false;
	else
	{
		if(a.price<=b.price)
		return false;
		else
		return true;
	}
}
using namespace std;
int main ()
{
	int n,m,i,j,v=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	scanf("%d",&s[i].price);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i].value);
		s[i].xjb=s[i].value*1.0/s[i].price;
	}
	sort(s,s+n,cmp);
	for(i=0;i<n;i++)
	{
		if(m>=s[i].price)
		{
			m-=s[i].price;
			v+=s[i].value;
		}
		if(m<=0)
		break;
	}
	printf("%d",v);
	return 0;
}
