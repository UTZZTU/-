#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[100010],k,b[100010];
struct os
{
	int l,r;
	os(int l=0,int r=0):l(l),r(r){}
}s[100010];
void dfs(int begin,int end)
{
	if(begin>end)
	return;
	int root=a[begin];
	int i=begin+1,j=end,pd1=0,pd2=0;
	while(a[i]<a[root]&&i<=end)
	{
		i++;
		pd1=1;
	}
	while(a[j]>=a[root]&&j>begin)
	{
		j--;
		pd2=1;
	}
	if(pd1==1)
	{
		s[root].l=a[begin+1];
		dfs(begin+1,i-1);
	}
	if(pd2==1)
	{
		s[root].r=a[j+1];
		dfs(j+1,end);
	}
}
void find(int x)
{
	queue<int> p;
	p.push(x);
	while(!p.size())
	{
		b[k++]=p.front();
		int t;
		t=p.front();
		p.pop();
		if(s[t].l!=0)
		p.push(s[t].l);
		if(s[t].r!=0)
		p.push(s[t].r);
	}
}
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(1,n);
	for(int i=1;i<=n;i++)
	printf("%d %d\n",s[i].l,s[i].r);
	return 0;
}