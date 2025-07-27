#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct dd
{
	int x,y;
	int dt;
	int bj;
}s1[1010];
struct zd
{
	int x,y;
	int bj;
}s2[1010];
bool cmp(dd x,dd y)
{
	return x.dt>y.dt;
}
int main ()
{
	int n,m,i,j,sum=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	double s;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s1[i].x>>s1[i].y>>s1[i].bj;
		s1[i].dt=0;
	}
	for(i=1;i<=m;i++)
	{
		cin>>s2[i].x>>s2[i].y>>s2[i].bj;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			s=sqrt((s2[i].x-s1[j].x)*(s2[i].x-s1[j].x)+(s2[i].y-s1[j].y)*(s2[i].y-s1[j].y));
			if(s<=s2[i].bj+s1[j].bj)
			{
				s1[j].dt=1;
			}
			
		}
	}
	sort(s1+1,s1+1+n,cmp);
	for(i=1;i<=m;i++)
	{
		for(j=i+1;j<=m;j++)
		{
			s=sqrt((s1[i].x-s1[j].x)*(s1[i].x-s1[j].x)+(s1[i].y-s1[j].y)*(s1[i].y-s1[j].y));
			if(s<=s1[i].bj+s1[j].bj&&s1[i].dt==1)
			{
				s1[j].dt=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(s1[i].dt==1)
		{
			sum++;
		}
		
	}
	printf("%d",sum);
	return 0;
}
