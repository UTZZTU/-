#include <bits/stdc++.h>
using namespace std;
int n,m,fa[100010],u,v,x,y,k;
string s;
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	scanf("%d%d",&n,&m);
	getchar();
	cin>>s;
	for(int i=0;i<n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		if(s[u-1]!=s[v-1]) continue;
		int eu=find(u),ev=find(v);
		if(eu!=ev)
		{
			fa[ev]=eu;
		}
	}
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&k);
		if(find(x)==find(y)&&(s[x-1]-'0')!=k) puts("No");
		else puts("Yes");
	}
	return 0;
}