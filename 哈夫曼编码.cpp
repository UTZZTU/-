#include <stdio.h>
#include <algorithm>
using namespace std;
struct zm
{
	char s;
	int n;
}a[26];
bool cmp(zm a,zm b)
{
	if(a.n>b.n)
	return true;
	else if(a.n<b.n)
	return false;
	else
	{
		if(a.s-b.s<0)
		return true;
		else
		return false;
	}
}
int main ()
{
	char w,i;
	for(i=0;i<26;i++)
	{
		a[i].s=i+'a';
		a[i].n=0;
	}
	while(scanf("%c",&w)!=EOF)
	{
		if(w=='\n')
		break;
		else
		{
			if(w>='a'&&w<='z')
			{
				a[w-'a'].n++;
			}
		}
	}
	sort(a,a+26,cmp);
	for(i=0;i<26;i++)
	{
		if(a[i].n!=0)
		printf("%c %d\n",a[i].s,a[i].n);
	}
	return 0;
}
