#include <stdio.h>
#include <algorithm>
using namespace std;
struct cl
{
	int c,k;
};
int fun(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}
int main ()
{
	struct cl s[50],s1[50],s2[50];
	int r,c,n,a,b,i,pd=0,hz=0,sz=0,z=-1,m=0,j1=0,j2=0,k1[50],k2[50],o1=0,o2=0,q1,q2;
	scanf("%d%d",&r,&c);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>r||a>c||b>r||b>c)
		{
			s[m].c=a;
			s[m].k=b;
			m++;
		}
		if(a>r&&b>c||a>c&&b>r)
		{
			pd=1;
		}
		if(a>r||b>r)
		{
			s1[j1].c=a;
			s1[j1].k=b;
			j1++;
		}
		if(a>c||b>c)
		{
			s2[j2].c=a;
			s2[j2].k=b;
			j2++;
		}
	}
	if(m==0)
	{
		printf("-1");
	}
	else
	{
		if(pd==1)
		{
			printf("1");
		}
		else
		{
			q1=r;
			q2=c;
			for(i=0;i<j1;i++)
			{
				if(s1[i].c>r&&s1[i].k>r)
				{
					k1[o1]=fun(s1[i].c,s1[i].k);
					o1++;
				}
				else if(s1[i].c>r)
				{
					k1[o1]=s1[i].k;
					o1++;
				}
				else if(s1[i].k>r)
				{
					k1[o1]=s1[i].c;
					o1++;
				}
			}
			sort(k1,k1+o1);
			for(i=o1-1;i>=0;i--)
			{
				q1-=k1[i];
				hz++;
				if(q1<=0)
				{
					if(hz>z)
					z=hz;
					break;
				}
			}
			for(i=0;i<j2;i++)
			{
				if(s2[i].c>c&&s2[i].k>c)
				{
					k2[o2]=fun(s2[i].c,s2[i].k);
					o2++;
				}
				else if(s2[i].c>c)
				{
					k2[o2]=s2[i].k;
					o2++;
				}
				else if(s2[i].k>c)
				{
					k2[o2]=s2[i].c;
					o2++;
				}
			}
			sort(k2,k2+o2);
			for(i=o2-1;i>=0;i--)
			{
				q2-=k2[i];
				sz++;
				if(q2<=0)
				{
					if(sz>z)
					z=sz;
					break;
				}
			}
			printf("%d",z);
		}
	}
	return 0;
}
