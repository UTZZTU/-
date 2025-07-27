#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct num
{
	int sl;
	int xz;
}s[200010];
int n,m;
bool cmp(num a,num b)
{
	if(a.sl!=b.sl)
	return a.sl<b.sl;
	else
	return a.xz<b.xz;
}
int main ()
{
	int u,mn=99999999;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%d",&s[i].sl);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i].xz);
		if(s[i].sl+s[i].xz<mn)
		mn=s[i].sl+s[i].xz;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		u=s[i].sl;
		else
		{
			if(u==mn)
			break;
			m-=(s[i].sl-s[i-1].sl)*(i-1);
			if(m<0)
			break;
			else
			u=s[i].sl;
			if(u==mn)
			break;
			
		}
	}
	cout<<u;
	return 0;
}