#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
struct num
{
	int xh;
	double z;
	double u;
}s[101];
bool cmp(num a,num b)
{
	if(a.z!=b.z)
	return a.z>b.z;
	else
	return a.xh<b.xh;
}
int n,m;
int gla[100];
int glb[100][100];
set<int> p;
int k;
int main ()
{
	double sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>gla[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>glb[i][j];
	}
	int gs;
	cin>>gs;
	for(int i=1;i<=gs;i++)
	{
		cin>>k;
		p.insert(k);
	}
	for(int i=1;i<=n;i++)
	{
		s[i].xh=i;
		double r=gla[i]*1.0/100;
		for(int j=1;j<=m;j++)
		{
			if(p.find(j)!=p.end())
			{
				r*=glb[i][j]*1.0/100;
			}
			else
			{
				if(glb[i][j]==0)
				continue;
				else
				r*=(100-glb[i][j])*1.0/100;
			}
		}
		s[i].u=r;
		sum+=r;
	}
	for(int i=1;i<=n;i++)
	{
		s[i].z=s[i].u*1.0/sum*100;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		
		printf("%d %.2f",s[i].xh,s[i].z);
		if(i!=n)
		printf("\n");
	}
	return 0;
}