#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> sk;
int ks=1,sds=0,zdjl=0;
struct cs
{
	string name;
	int rs;
}s[1010];
struct yu
{
	vector<int> a;
	int xds;
	int jfcz;
	int zdjl;
}w[1010];
bool cmp(yu a,yu b)
{
	if(a.zdjl!=b.zdjl)
	return a.zdjl<b.zdjl;
	else if(a.jfcz!=b.jfcz)
	return a.jfcz>b.jfcz;
	else 
	return a.xds>b.xds;
}
int mb;
struct edge
{
	int from,to,w;
	edge(int a,int b,int c)
	{from=a,to=b,w=c;}
};
vector<edge> e[210];
void dfs(int x)
{
	if(e[x].size()==0)
	return;
	if(x==mb)
	{
		for(auto it=sk.begin();it!=sk.end();it++)
		{
			w[ks].a.push_back(*it);
		}
		w[ks].jfcz=sk.size();
		w[ks].xds=sds;
		w[ks].zdjl=zdjl;
		ks++;
		return;
	}
	else
	{
		for(int i=0;i<e[x].size();i++)
		{
			vector<int>::iterator it=find(sk.begin(),sk.end(),e[x][i].to);
			if(it!=sk.end())
			continue;
			sds+=s[e[x][i].to].rs;
			sk.push_back(e[x][i].to);
			zdjl+=e[x][i].w;
			dfs(e[x][i].to);
			sds-=s[e[x][i].to].rs;
			sk.pop_back();
			zdjl-=e[x][i].w;
		}
	}
}
int main ()
{
	map<string,int> mp;
	int n,k,i,j,l,zs;
	cin>>n>>k;
	string wf,df,a,b;
	cin>>wf>>df;
	s[1].name=wf;
	mp[wf]=1;
	for(i=2;i<=n;i++)
	{
		cin>>s[i].name>>s[i].rs;
		mp[s[i].name]=i;
		if(s[i].name==df)
		mb=i;
	}
	for(i=1;i<=k;i++)
	{
		cin>>a>>b>>l;
		int r1,r2;
		r1=mp[a];
		r2=mp[b];
		e[r1].push_back(edge(r1,r2,l));
		e[r2].push_back(edge(r2,r1,l));
	}
	sk.push_back(1);
	dfs(1);
	sort(w+1,w+ks,cmp);
	for(auto it=w[1].a.begin();it!=w[1].a.end();it++)
	{     
	     if(it!=w[1].a.begin())
		cout<<"->"<<s[*it].name;
		else
		cout<<s[*it].name;
	}
	cout<<endl;
	i=1;
	zs=1;
	while(w[i].zdjl==w[i+1].zdjl)
	{
		zs++;
		i++;
	}
	printf("%d %d %d",zs,w[1].zdjl,w[1].xds);
	return 0;
}