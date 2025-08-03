#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
const int N = 2e5 + 10;
int m,q,n,x,op,u,v,w,ww[100010];
multiset<int> mul[100010];
vector<int> vec[100010];
struct Node
{
    int l,r;
    int v;
}tr[N * 4];
void push_up(int u)
{
//	tr[u].v=0x3f3f3f3f;
//	if(tr[u << 1].v>0) tr[u].v=min(tr[u].v,tr[u << 1].v);
//	if(tr[u << 1 | 1].v>0) tr[u].v=min(tr[u].v,tr[u << 1 | 1].v);
    tr[u].v=min(tr[u << 1].v,tr[u << 1 | 1].v);
//    cout<<"push_up"<<tr[u].v<<endl;
}
void build(int u,int l,int r)
{
//    tr[u]={l,r};
//    if(l==r)
//    {
//    	tr[l].v=*mul[l].begin();
//    	cout<<"build"<<tr[l].v<<endl;
//    	cout<<l<<" "<<r<<endl;
//    	return;
//	}
//    int mid = l + r >> 1;
//    build(u<<1,l,mid),build(u << 1 | 1, mid+1, r);
//    push_up(u);
    
    if(l==r) tr[u]={l,r,ww[r]};
    else
    {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        push_up(u);
    }
}
int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v;

        int mid = tr[u].l + tr[u].r >> 1;
        int v=0;
        if (l<=mid) v=query(u<<1, l,r);
        if(r>mid) v=min(v, query(u<<1|1,l,r));
        return v;
}
void modify(int u,int x,int v)
{
    if(tr[u].l==x&&tr[u].r==x) tr[u].v=v;
    else
    {
        int mid = tr[u].l+tr[u].r>>1;
        if(x<=mid) modify(u<<1, x,v);
        else if(x>mid) modify(u<<1|1,x,v);
        push_up(u);
    }
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			mul[i].insert(x);
			vec[i].push_back(x);
		}
		ww[i]=*mul[i].begin();
	}
	build(1,1,n);
//	cout<<"query"<<query(1,1,n)<<endl;
	cin>>q;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>u>>v>>w;
			int x=vec[u][v-1];
			mul[u].erase(mul[u].lower_bound(x));
			vec[u][v-1]=w;
			mul[u].insert(w);
			modify(1,u,*mul[u].begin());
		}
		else
		{
			cin>>u;
			cout<<query(1,1,u)<<endl;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}