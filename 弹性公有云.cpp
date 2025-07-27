#include <bits/stdc++.h>
using namespace std;
int t,n,m;
double p[10];
struct node
{
	double f[10];
}e[510];
int find()
{
	double minn=0x3f3f3f3f;
	int flag,pos=-1;
	for(int i=1;i<=n;i++)
	{
		flag=1;
		for(int j=1;j<=5;j++)
		{
			if(e[i].f[j]<p[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			if(e[i].f[6]<minn)
			{
				minn=e[i].f[6];
				pos=i;
			}
		}
	}
	return (int)pos;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=6;j++)
			{
				scanf("%lf",&e[i].f[j]);
			}
		}
		while(m--)
		{
			for(int i=1;i<=5;i++)
			{
				scanf("%lf",&p[i]);
			}
			cout<<find()<<endl;
		}
	}
	return 0;
}