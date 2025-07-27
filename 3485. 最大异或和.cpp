#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
int tr[N][2],cnt[N],idx,n,m,f[N],k,maxx;
void insert(int x,int v)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int u=x>>i&1;
		if(!tr[p][u]) tr[p][u]=++idx;
		p=tr[p][u];
		cnt[p]+=v;
	}
}

int query(int x)
{
	int res=0,p=0;
	for(int i=30;i>=0;i--)
	{
		int u=x>>i&1;
		if(cnt[tr[p][!u]]) res=res*2+1,p=tr[p][!u];
		else res=res*2,p=tr[p][u]; 
	}
	return res;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		f[i]=f[i-1] ^ k;
	}
	insert(f[0],1);
	for(int i=1;i<=n;i++)
	{
		if(i-m-1>=0) insert(f[i-m-1],-1);
		maxx=max(maxx,query(f[i]));
		insert(f[i],1);
	}
	cout<<maxx<<endl;
	return 0;
}