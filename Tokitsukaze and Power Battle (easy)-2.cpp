#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mx,sum;
		void init()
		{
			mx=-LLINF;
			sum=0;
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],bit[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.sum=x.sum+y.sum;
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		t[ls].mx+=tag[id];
		t[rs].mx+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mx=bit[l]-2*a[l];
			t[id].sum=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			if(qop==1) t[id].sum=qv;
			else
			{
				t[id].mx+=qv;
				tag[id]+=qv;
			}
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v,int op)
	{
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,1);
	}
	type ask_max(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).mx;
	}
	type ask_sum(int l,int r)
	{
		if(l>r) return type(0);
		ql=l;
		qr=r;
		return query(1,n,1).sum;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
ll a[MAX];
int main()
{
	int T,n,q,i,op,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		tr.bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			tr.a[i]=a[i];
			tr.bit[i]=tr.bit[i-1]+a[i];
		}
		tr.build(n);
		while(q--)
		{
			scanf("%d%d%d",&op,&x,&y);
			if(op==1)
			{
				tr.upd(x,x,2*a[x]-2*y,2);
				tr.upd(x,n,y-a[x],2);
				a[x]=y;
				tr.upd(x,x,a[x],1);
			}
			else printf("%lld\n",tr.ask_max(x+1,y)-tr.ask_sum(1,x-1));
		}
	}
	return 0;
}
