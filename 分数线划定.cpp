#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct p
{
	int num,mark;
}s[5050];
bool cmp(p a,p b)
{
	if(a.mark>b.mark)
	return true;
	else if(a.mark<b.mark)
	return false;
	else
	{
		return a.num<b.num;
	}
}
int main ()
{
	int n,m,i,j,k,sum=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i].num,&s[i].mark);
	}
	sort(s+1,s+n+1,cmp);
	k=floor(m*1.5);
	j=s[k].mark;
	for(i=1;i<=n;i++)
	{
		if(s[i].mark>=j)
		sum++;
	}
	printf("%d %d\n",j,sum);
	for(i=1;i<sum;i++)
	{
		printf("%d %d\n",s[i].num,s[i].mark);
	}
	printf("%d %d",s[i].num,s[i].mark);
	 return 0;	
}
