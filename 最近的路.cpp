#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int mn=-1,q,h,f,visit[2000];
struct edge
{
	int value;
	int from,to;
	edge(int a,int b,int c){from=a;to=b;value=c;}
};
vector<edge> s[210];
void dfs(int n)
{
	if(n==h)
	{
		if(mn==-1)
		mn=f;
		else
		mn=min(mn,f);
		return ;
	}
	if(s[n].size()==0)
	return ;
	int i;
	visit[n]=1;
	for(i=0;i<s[n].size();i++)
	{
		int j=s[n][i].to;
		f+=s[n][i].value;
		if(visit[s[n][i].to]!=1)
		dfs(s[n][i].to);
		f-=s[n][i].value;
	}
}
int main ()
{
	int n,e,m,u,v,w;
	cin>>n>>e>>m;
	for(int i=1;i<=e;i++)
	{
		cin>>u>>v>>w;
		s[u].push_back(edge(u,v,w));
	}
	for(int i=1;i<=m;i++)
	{
		memset(visit,0,sizeof(visit));
		cin>>q>>h;
		mn=-1;
		f=0;
		dfs(q);
		if(mn!=-1)
		cout<<mn<<endl;
		else
		printf("No solution\n");
	}
	return 0;
}