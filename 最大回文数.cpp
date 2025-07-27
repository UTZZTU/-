#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct num
{
	char s[35];
}q[10010];
bool cmp(num a,num b)
{
	if(strlen(a.s)>strlen(b.s))
	return true;
	else if(strlen(a.s)<strlen(b.s))
	return false;
	else
	{
		if(strcmp(a.s,b.s)>=0)
		return true;
		else
		return false;
		
	}
}
int fun(struct num p)
{
	int l,i;
	l=strlen(p.s);
	for(i=0;i<l;i++)
	{
		if(p.s[i]!=p.s[l-1-i])
		return 0;
	}
	return 1;
}
int main ()
{
	int n,i,pd=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",q[i].s);
	}
	sort(q,q+n,cmp);
	for(i=0;i<n;i++)
	{
		if(fun(q[i]))
		{
			printf("%s",q[i].s);
			break;
		}
	}
	return 0;
}
