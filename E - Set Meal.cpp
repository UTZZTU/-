#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,l,k1,k2;
map<pair<int,int>,bool> mp1,mp2;
struct node
{
	int pos,num;
}s1[100010],s2[100010];
struct tt
{
	int i,j,num;
	inline bool operator<(const tt &x) const
	{
		return num<x.num;
	}
};
bool cmp(node x,node y)
{
	if(x.num!=y.num) return x.num<y.num;
	return x.pos<y.pos;
}
int bfs()
{
	priority_queue<tt> p;
	p.push({n,m,s1[n].num+s2[m].num});
	while(!p.empty())
	{
		auto u=p.top();
//		cout<<u.num<<endl;
		p.pop();
		int x=u.i,y=u.j;
		int tt1=s1[x].pos,tt2=s2[y].pos;
		if(mp2[{x,y}]) continue;
		mp2[{x,y}]=true;
		if(!mp1[{tt1,tt2}]) return u.num;
		p.push({x-1,y,s1[x-1].num+s2[y].num});
		p.push({x,y-1,s1[x].num+s2[y-1].num});
	} 
}
int main ()
{
	scanf("%d%d%d",&n,&m,&l);
	s1[0].num=0,s1[0].pos=0,s2[0].num=0,s2[0].pos=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s1[i].num);
		s1[i].pos=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&s2[i].num);
		s2[i].pos=i;
	}
	sort(s1+1,s1+1+n,cmp);
	sort(s2+1,s2+1+m,cmp);
	for(int i=1;i<=l;i++)
	{
		scanf("%d%d",&k1,&k2);
		mp1[{k1,k2}]=true;
	}
	cout<<bfs();
	return 0;
}