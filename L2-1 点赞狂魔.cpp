#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int fun(int n)
{
	int i,k;
	set<int> a;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		a.insert(k);
	}
	return a.size();
}
struct p
{
	char name[100];
	double pjcs;
	int gs,zz;
	
}s[105];
bool cmp(p a,p b)
{
	if(a.zz!=b.zz)
	return a.zz>b.zz;
	else
	return a.pjcs<b.pjcs;
}
int main ()
{
	int n,i,zd=0;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%s %d",s[i].name,&s[i].gs);
		s[i].zz=fun(s[i].gs);
		s[i].pjcs=s[i].gs*1.0/s[i].zz;
	}
	sort(s+1,s+1+n,cmp);
	if(n>=3)
	{
		for(i=1;i<3;i++)
	{
		printf("%s ",s[i].name);
	}
	printf("%s",s[i].name);
	}
	else
	{
		i=1;
		printf("%s",s[i].name);
		i++;
		for(i;i<=n;i++)
		printf(" %s",s[i].name);
		for(i;i<=3;i++)
		printf(" -");
	}
	return 0;
}