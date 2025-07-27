#include <bits/stdc++.h>
using namespace std;
int x[110],y[110];
int hav[110],fa[110];
set<int> st;
int n,m;
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
}
bool islt(vector<int> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		int j=vec[i];
		hav[j]=0;
		for(int k=1;k<=n;k++) fa[k]=k;
		for(int k=1;k<=m;k++)
		{
			int xx=x[k],yy=y[k],eu=find(x[k]),ev=find(y[k]);
			if(hav[xx]&&hav[yy]&&eu!=ev)
			{
				fa[eu]=ev;
			}
		}
		set<int> ss;
		for(int k=1;k<=n;k++)
		{
			if(hav[k])
			{
				ss.insert(find(k));
			}
		}
		hav[j]=1;
		if(ss.size()!=1) return false;
	}
	return true;
}
//struct node
//{
//	int u,v;
//}e[1010];
//bool istree(vector<int> vec)
//{
//	if(vec.size()==2) return true;
//	for(int i=0;i<vec.size();i++)
//	{
//		int j=vec[i];
//		hav[j]=0;
//		for(int k=1;k<=m;k++)
//		{
//			int xx=x[i],yy=y[i];
//			
//		}
//	}
//}
bool liant(vector<int> vec)
{
	for(int k=1;k<=n;k++) fa[k]=k;
	for(int k=1;k<=m;k++)
	{
		int xx=x[k],yy=y[k],eu=find(x[k]),ev=find(y[k]);
		if(hav[xx]&&hav[yy]&&eu!=ev)
		{
			fa[eu]=ev;
		}
	}
	set<int> ss;
	for(int k=1;k<=n;k++)
	{
		if(hav[k])
		{
			ss.insert(find(k));
		}
	}
	if(ss.size()!=1) return false;
	else return true;
}
void dfs(int level,vector<int> vec)
{
	if(vec.size())
	{
		if(vec.size()==1)
		{
			st.insert(1);
		}
		else
		{
			if(liant(vec)&&islt(vec))
			{
				st.insert(vec.size());
			}
		}
	}
	if(level>n) return;
	vec.push_back(level);
	hav[level]=1;
	dfs(level+1,vec);
	vec.pop_back();
	hav[level]=0;
	dfs(level+1,vec);
}
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int xx,yy;
			cin>>xx>>yy;
			x[i]=xx;
			y[i]=yy;
		}
		vector<int> vec;
		dfs(1,vec);
		vector<int> v;
		for(auto c:st)
		{
			v.push_back(c);
		}
		cout<<v[v.size()-1]<<" "<<v[v.size()-2]<<endl;
	}
	return 0;
}
