#include <bits/stdc++.h>
using namespace std;
int t,a,b,fa[30010],s[30010],dist[30010];
string str;
void init()
{
	for(int i=1;i<=30000;i++)
	{
		fa[i]=i;
		s[i]=1;
	}
}
int find(int x)
{
	if(fa[x]!=x)
	{
		int root=find(fa[x]);
		dist[x]+=dist[fa[x]];
		fa[x]=root;
	}
	return fa[x];
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>t;
	while(t--)
	{
		cin>>str>>a>>b;
		if(str=="M")
		{
			int pa=find(a),pb=find(b);
			if(pa!=pb)
			{
				dist[pa]=s[pb];
				s[pb]+=s[pa];
				fa[pa]=pb;
			}
		}
		else
		{
			int pa=find(a),pb=find(b);
			if(pa!=pb) cout<<"-1"<<endl;
			else cout<<max(abs(dist[a]-dist[b])-1,0)<<endl;
		}
	}
	return 0;
}