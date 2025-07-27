#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5+10;

int lowbit(int x) {
	return x&-x;
}


int n,m;
int a[N],t[N];

void add(int x,int d) {
	for(; x<=n; x+=lowbit(x)) {
		t[x]+=d;
	}
}

int ask(int x) {
	int res=0;
	for(; x; x-=lowbit(x)) {
		res+=t[x];
	}
	return res;
}

void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		t[i]=0;
	}
	t[n+1]=0;
	t[0]=0;
	while(m--) {
		int c;
		cin>>c;
		if(c==2) {
			int x;
			cin>>x;
			int res=ask(x);
			if(res!=0) {
				add(x,-res);
				add(x+1,res);
			}
			while(res--) {
				int sum=0;
				while(a[x]) {
					sum+=a[x]%10;
					a[x]/=10;
				}
				a[x]=sum;
				if(sum==(sum%10)) {
					break;
				}
			}
			cout<<a[x]<<endl;
		} else {
			int l,r;
			cin>>l>>r;
			add(l,1);
			add(r+1,-1);
		}
	}
}

signed main() {

	int _=1;
	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}