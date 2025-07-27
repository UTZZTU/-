#include<stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct stu
{
	int fs,nj;
}s[205];
bool cmp(stu a,stu b)
{
	if(a.fs>b.fs)
	return true;
	else if(a.fs<b.fs)
	return false;
	else
	{
		if(a.nj<=b.nj)
		return true;
		else
		return false;
	}
}
int main ()
{
	int n,i,a[7],j,sum;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&s[i].fs,&s[i].nj);
	}
	sort(s,s+n,cmp);
	a[s[0].nj]++;
	if(n==1)
	printf("0");
	else
	{
		printf("0\n");
		for(i=1;i<n-1;i++)
		{
			sum=0;
			for(j=1;j<s[i].nj;j++)
			{
				sum+=a[j];
			}
			printf("%d\n",sum);
			a[s[i].nj]++;
		}
		sum=0;
		for(j=1;j<s[i].nj;j++)
			{
				sum+=a[j];
			}
			printf("%d",sum);
	}
	return 0;
 } 
