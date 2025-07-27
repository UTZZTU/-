#include <iostream>
using namespace std;
int n,m,x,y,res,fa[200010];
int find(int x)
{
	while(x!=fa[x])
	{
		x=fa[x]=fa[fa[x]];
	}
	return x;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		int eu=find(x),ev=find(y);
		if(eu!=ev)
		fa[eu]=ev;
		else
		res++;
	}
	cout<<res;
	return 0;
}