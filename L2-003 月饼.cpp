#include <bits/stdc++.h>
using namespace std;
struct mooncake
{
	double kc,zsj;
	double xjb;
}s[1010];
bool cmp(mooncake a,mooncake b)
{
	return a.xjb>b.xjb;
}
int n,d;
double num=0;
int main ()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	scanf("%lf",&s[i].kc);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&s[i].zsj);
		s[i].xjb=s[i].zsj*1.0/s[i].kc;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(d-s[i].kc>=0)
		{
			num+=s[i].zsj;
			d-=s[i].kc;
		}
		else
		{
			num+=d*1.0/s[i].kc*s[i].zsj;
			break;
		}
	}
	printf("%.2f",num);
	return 0;
}