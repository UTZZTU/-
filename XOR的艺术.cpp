#include<bits/stdc++.h>
#define ll long long
#define ls u<<1
#define rs u<<1|1
using namespace std;
const int maxn = 2e5 + 5;
struct Segtree{
	int l,r;
	ll sum,laz;
}tr[maxn << 2];
int a[maxn];
int n,m;
void pushup(int u){
	tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void pushdown(int u){
	if(tr[u].laz){
		tr[ls].sum = tr[ls].r - tr[ls].l + 1 - tr[ls].sum;
		tr[rs].sum = tr[rs].r - tr[rs].l + 1 - tr[rs].sum;
		tr[ls].laz = !tr[ls].laz;
		tr[rs].laz = !tr[rs].laz;
		tr[u].laz = 0;
	}
}
void build(int u, int l, int r){
	tr[u].l = l, tr[u].r = r;
	if(l == r){
		tr[u].sum = a[l];
		tr[u].laz = 0;
		return ;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	build(ls, l, mid);
	build(rs, mid+1, r);
	pushup(u);
}
void update(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
		tr[u].laz = !tr[u].laz;
		return ;
	}
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if(l <= mid)update(ls, l, r);
	if(r > mid)update(rs, l, r);
	pushup(u);
}
ll query(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].sum;
	}
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	ll res = 0;
	if(l <= mid)res += query(ls, l, r);
	if(r > mid)res += query(rs, l, r);
	return res; 
}
int main(){
	cin >> n >> m;
	string str;
	cin >> str;
	for(int i = 0; i < n; i++){
		a[i + 1] = (str[i] - '0');
	}
	build(1, 1, n);
	while(m--){
		int op,l,r;
		cin >> op >> l >> r;
		if(op == 0){
			update(1, l, r);
		}else{
			cout << query(1, l, r) << endl;
		}
	}
} 
