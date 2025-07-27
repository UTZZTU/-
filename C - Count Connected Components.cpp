#include <iostream>
#include <set>
using namespace std;
int fa[110],n,m,u,v;
set<int> st;
int find(int x)
{
	while(x!=fa[x])
	x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	while(m--)
	{
		scanf("%d%d",&u,&v);
		int l=find(u),r=find(v);
		if(l==r)
		continue;
		fa[l]=r;
	}
	for(int i=1;i<=n;i++)
	{
		int f=find(i);
		st.insert(f);
	}
	cout<<st.size();
	return 0;
}