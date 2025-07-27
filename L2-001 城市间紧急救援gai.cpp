#include <bits/stdc++.h>
using namespace std;
int n,m,s,d;
struct node
{
	int v,w;
};
vector<node> G[510];
vector<int> late;
int rs[510],maxn=1234567890,maxm=0,tot;
bool vis[510];
vector<int> ls;
void dfs(int x,int len,int sum)
{
	if(x==d)
	{
		if(len<maxn)
		{
			tot=1;
			maxn=len;
			maxm=sum;
			late=ls;
		}
		else if(len==maxn)
		{
			tot++;
			if(sum>maxm)
			{
				maxm=sum;
				late=ls;
			}
		}
		return;
	}
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i].v;
		if(!vis[v])
		{
			vis[v]=true;
			ls.push_back(v);
			dfs(v,len+G[x][i].w,sum+rs[v]);
			vis[v]=false;
			ls.pop_back();
		}
	}
}
int main()
{
   scanf("%d %d %d %d",&n,&m,&s,&d);
   for(int i=0;i<n;i++)
   scanf("%d",&rs[i]);
   for(int i=1,u,v,w;i<=m;i++)
   {
   	  scanf("%d %d %d",&u,&v,&w);
   	  G[u].push_back((node){v,w});
   	  G[v].push_back((node){u,w});
   }
   ls.push_back(s);
	vis[s]=true;
	dfs(s,0,rs[s]);
	cout<<tot<<" "<<maxm<<endl;
	for(auto it=late.begin();it!=late.end();it++)
	{
		if(it!=late.begin())
		cout<<" ";
		cout<<*it;
	}
	return 0;
}