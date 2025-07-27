#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int w[N],n,m,l,r,d;
string u;
bool check(string u)
{
	int res=0;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]==' ')
		res++;
	}
	vector<int> vec;
	int num=0,pos=1;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='-')
		{
			pos=-1;
		}
		else if(u[i]==' ')
		{
			vec.push_back(num*pos);
			num=0,pos=1;
		}
		else
		{
			num=num*10+(u[i]-'0');
		}
	}
	vec.push_back(num*pos);
	if(res==1)
	{
		l=vec[0],r=vec[1];
//		cout<<"l:"<<l<<" r:"<<r<<endl;
	}
	else
	{
		l=vec[0],r=vec[1],d=vec[2];
//		cout<<"l:"<<l<<" r:"<<r<<" d:"<<d<<endl;
	}
	return res==1;
}
struct Node{
	int l,r;
	int minn,add;
}tr[N*4];
void push_up(int u)
{
	tr[u].minn=min(tr[u<<1].minn,tr[u<<1|1].minn);
}
void push_down(int u)
{
	if(tr[u].add)
	{
		tr[u<<1].minn+=tr[u].add,tr[u<<1].add+=tr[u].add;
		tr[u<<1|1].minn+=tr[u].add,tr[u<<1|1].add+=tr[u].add;
		tr[u].add=0;
	}
}
void build(int u,int l,int r)
{
	if(l==r) tr[u]={l,r,w[r],0};
	else
	{
		tr[u]={l,r};
		tr[u].add=0;
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		push_up(u);
	}
}
void modify(int u,int l,int r,int d)
{
//	cout<<l<<" "<<r<<" "<<u<<endl;
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].add+=d;
		tr[u].minn+=d;
	}
	else
	{
		push_down(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid) modify(u<<1,l,r,d);
		if(r>mid) modify(u<<1|1,l,r,d);
		push_up(u);
	}
}
int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].minn;
	push_down(u);
	int mid=tr[u].l+tr[u].r>>1;
	int minn=1e18;
	if(l<=mid) minn=min(minn,query(u<<1,l,r));
	if(r>mid) minn=min(minn,query(u<<1|1,l,r));
	return minn;
}
signed main ()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&w[i]);
	}
	build(1,0,n-1);
	scanf("%lld",&m);
	getchar();
	while(m--)
	{
		getline(cin,u);
		if(check(u))
		{
			if(l<=r)
			printf("%lld\n",query(1,l,r));
			else
			{
				printf("%lld\n",min(query(1,l,n-1),query(1,0,r)));
			}
		}
		else
		{
			if(l<=r)
			{
				modify(1,l,r,d);
			}
			else
			{
				modify(1,l,n-1,d),modify(1,0,r,d);
			}
		}
	}
	return 0;
}