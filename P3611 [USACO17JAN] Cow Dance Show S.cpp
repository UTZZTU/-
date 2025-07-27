#include <bits/stdc++.h>
using namespace std;
int n,t,k,f[10010];

//multiset<int> st;
bool check(int x)
{
	priority_queue<int,vector<int>,greater<int>> p;
	for(int i=1;i<=x&&i<=n;i++)
	{
		p.push(f[i]);
	}
	for(int i=x+1;i<=n;i++)
	{
		int q=p.top();
		p.pop();
		p.push(q+f[i]);
	}
	int y;
	while(p.size())
	{
		y=p.top();
		p.pop();
	}
	return y<=t;
}
int main ()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}