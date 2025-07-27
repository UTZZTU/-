#include <bits/stdc++.h>
using namespace std;
#define il inline
int n,m,fa[5050];
il int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
il int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
int main ()
{
	while(n=read())
	{
		if(n==0)
		break;
		m=read();
		for(int i=1;i<=n;i++)
		fa[i]=i;
		for(int i=1,x,y;i<=m;i++)
		{
			x=read();y=read();
			x=find(x);y=find(y);
			fa[y]=x;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		if(fa[i]==i)
		cnt++;
		cout<<cnt-1<<endl;
	}
	return 0;
}