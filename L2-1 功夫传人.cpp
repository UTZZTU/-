#include <stdio.h>
#include <math.h>
typedef long long ll;
struct p
{
	int dz;
	int a[100];
	double gl;
	int jb;
}s[100005];
int main ()
{
	double z=0,ks,r;
	int n,i,j;
	ll sum;
	scanf("%d %lf %lf",&n,&ks,&r);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i].dz);
		for(j=0;j<s[i].dz;j++)
		{
			scanf("%d",&s[i].a[j]);
		}
		if(s[i].dz==0)
		scanf("%d",&s[i].jb);
	}
	s[0].gl=ks;
	for(i=0;i<n;i++)
	{
		if(s[i].dz==0)
		continue;
		for(j=0;j<s[i].dz;j++)
		{
			s[s[i].a[j]].gl=(100-r)*1.0/100*s[i].gl;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<s[i].dz;j++)
		{
			s[s[i].a[j]].gl=(100-r)*1.0/100*s[i].gl;
		}
		if(s[i].dz==0)
		{
			s[i].gl*=s[i].jb;
			z+=s[i].gl;
		}
		
	}
	sum=floor(z);
	printf("%lld",sum);
	return 0;
}