#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point
{
	int x,y,p;
	int sy;
}s[100010];
bool cmp(point a,point b)
{
	if(a.x!=b.x)
	return a.x<b.x;
	else
	return a.y<b.y;
}
int main ()
{
	ll sum=0;
	int n,xi,yi,pi,k=1,js=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&xi,&yi,&pi);
		sum+=pi;
		if(pi==1)
		{
			s[k].x=xi;
			s[k].y=yi;
			s[k].p=pi;
			s[k].sy=0;
			k++;
		}
		else
		js++;
	}
	sort(s+1,s+k,cmp);
	for(int i=1;i<k;i++)
	{
		if(s[i].sy==1)
		continue;
		xi=s[i].x;
		yi=s[i].y;
		for(int j=i+1;j<k;j++)
		{
			if(s[j].sy==1)
			continue;
			if(xi*s[j].y==s[j].x*yi)
			s[j].sy=1;
		}
		js++;
	}
	printf("%lld %d",sum,js);
	return 0;
}