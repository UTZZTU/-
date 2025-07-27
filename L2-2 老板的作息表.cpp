#include <iostream>
#include <algorithm>
using namespace std;
struct p
{
	int h1,h2,m1,m2,s1,s2;
}s[101000];
bool cmp(p x,p y)
{
	if(x.h2!=y.h1)
	return x.h2<y.h1;
	else if(x.m2!=y.m1)
	return x.m2<y.m1;
	else
	return x.s2<=y.s1;
}
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d:%d:%d - %d:%d:%d",&s[i].h1,&s[i].m1,&s[i].s1,&s[i].h2,&s[i].m2,&s[i].s2);
	}
	sort(s+1,s+1+n,cmp);
	if(!(s[1].h1==0&&s[1].m1==0&&s[1].s1==0))
	{
		printf("00:00:00 - %02d:%02d:%02d\n",s[1].h1,s[1].m1,s[1].s1);
	}
	for(int i=1;i<n;i++)
	{
		if(s[i].h2==s[i+1].h1&&s[i].m2==s[i+1].m1&&s[i].s2==s[i+1].s1)
		continue;
		printf("%02d:%02d:%02d - %02d:%02d:%02d\n",s[i].h2,s[i].m2,s[i].s2,s[i+1].h1,s[i+1].m1,s[i+1].s1);
	}
	if(!(s[n].h2==23&&s[n].m2==59&&s[n].s2==59))
	{
		printf("%02d:%02d:%02d - 23:59:59\n",s[n].h2,s[n].m2,s[n].s2);
	}
	return 0;
}