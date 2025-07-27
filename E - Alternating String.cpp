#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,q,opt,x,y;
char ch;
struct node{
	int l,r,tag,ans;
}tree[N<<2];
void pushup(int rt){
	if(tree[rt*2].r!=tree[rt*2+1].l)tree[rt].ans=1;
	else tree[rt].ans=0;
	tree[rt].ans&=tree[rt*2].ans;
	tree[rt].ans&=tree[rt*2+1].ans;
	tree[rt].l=tree[rt*2].l;
	tree[rt].r=tree[rt*2+1].r;
}
void update(int rt,int l,int r,int x,int d){
	if(l==r){
		tree[rt].l=tree[rt].r=d;
		tree[rt].ans=1;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)update(rt*2,l,mid,x,d);
	else update(rt*2+1,mid+1,r,x,d);
	pushup(rt);
}
void pushdown(int rt){
	if(tree[rt].tag){
		tree[rt*2].l^=1;
		tree[rt*2].r^=1;
		tree[rt*2].tag^=1;
		
		tree[rt*2+1].l^=1;
		tree[rt*2+1].r^=1;
		tree[rt*2+1].tag^=1;
		
		tree[rt].tag=0;
	}
}
void modify(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		tree[rt].l^=1;
		tree[rt].r^=1;
		tree[rt].tag^=1;
		return;
	}
	pushdown(rt);
	int mid=l+r>>1;
	if(mid>=x)modify(rt*2,l,mid,x,y);
	if(mid<y)modify(rt*2+1,mid+1,r,x,y);
	pushup(rt);
}
int query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return tree[rt].ans;
	}
	pushdown(rt);
	int mid=l+r>>1,ans=1;
	if(mid>=x)ans&=query(rt*2,l,mid,x,y);
	if(mid<y)ans&=query(rt*2+1,mid+1,r,x,y);
	if(x<=mid&&mid<y&&tree[rt*2].r==tree[rt*2+1].l)ans=0;
	return ans;
}
int main(){
	cin >>n>>q;
	for(int i=1;i<=n;i++){
		cin >>ch;
		update(1,1,n,i,ch-'0');
	}
	while(q--){
		cin >>opt>>x>>y;
		if(opt==1){
			modify(1,1,n,x,y);
		}else{
			if(query(1,1,n,x,y))cout <<"Yes"<<endl;
			else cout <<"No"<<endl;
		}
	}
	return 0;
}
