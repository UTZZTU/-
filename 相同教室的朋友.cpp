#include <bits/stdc++.h>
using namespace std;
int s,n,m,fa[5010],x,y;
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	cin>>s>>n>>m;
	for(int i=1;i<=s;i++) fa[i]=i;
	while(n--)
	{
		cin>>x>>y;
		int eu=find(x),ev=find(y);
		if(eu==ev) continue;
		fa[ev]=eu;
	}
	while(m--)
	{
		cin>>x>>y;
        if(x==y)
        {
            cout<<"?"<<endl;
            continue;
        }
		int eu=find(x),ev=find(y);
		if(eu==ev)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}