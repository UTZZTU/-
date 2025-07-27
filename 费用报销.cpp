#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,k,mx=0;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct pj
{
	int y,r,q;
}s[1010];
bool cmp(pj a,pj b)
{
	if(a.y!=b.y)
	return a.y<b.y;
	else
	return a.r<b.r;
}
void dfs(int x,int t,int sc)
{
	if(x>n||sc>n)
	return ;
	if(t>m)
	return;
	mx=max(mx,t);
	if(sc==0)
	{
		dfs(x+1,t+s[x+1].q,x);
		dfs(x+1,t,sc);
	}
	else
	{
		if(s[x].y==s[sc].y&&s[x].r-s[sc].r>=k||s[x].y!=s[sc].y&&s[x].r+a[s[sc].y]-s[sc].r>=k)
		{
		dfs(x+1,t+s[x+1].q,x);
		dfs(x+1,t,x);
		}
	}
}
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	scanf("%d %d %d",&s[i].y,&s[i].r,&s[i].q);
	sort(s+1,s+1+n,cmp);
	dfs(0,0,0);
	cout<<mx;
	return 0;
}