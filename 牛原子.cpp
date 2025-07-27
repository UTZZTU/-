#include <bits/stdc++.h>
using namespace std;
struct node
{
	int cs,js,gs;
	char c;
}s[110];
bool cmp(node a,node b)
{
	if(a.cs!=b.cs)
	return a.cs<b.cs;
	else
	return a.js<b.js;
}
int t,a[20]={0,1,2,2,3,3,4,3,4,5,4,5,6,4,5,6,7,5,6,7},b[20]={0,2,2,6,2,6,2,10,6,2,10,6,2,14,10,6,2,14,10,6},n;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i=1;
		while(i<=19&&n)
		{
			s[i].cs=a[i];
			s[i].gs=min(b[i],n);
			n-=s[i].gs;
			if(b[i]==2)
			{
				s[i].js=1;
				s[i].c='s';
			}
			else if(b[i]==6)
			{
				s[i].js=2;
				s[i].c='p';
			}
			else if(b[i]==10)
			{
				s[i].js=3;
				s[i].c='d';
			}
			else
			{
				s[i].js=4;
				s[i].c='f';
			}
			i++;
		}
		sort(s+1,s+i,cmp);
		for(int j=1;j<i;j++)
		{
			if(j!=1)
			printf(" ");
			printf("%d%c%d",s[j].cs,s[j].c,s[j].gs);
		}
		printf("\n");
	}
	return 0;
}