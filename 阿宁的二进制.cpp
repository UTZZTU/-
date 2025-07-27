#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int get_num(int x) {
	int res=0;
	while(x) {
		res+=x%2;
		x/=2;
	}
	return res;
}
int ans[N],n,q,x,k;
int main() {

	scanf("%d%d",&n,&q);
	priority_queue<int>Q;
	for(int i=1; i<=n; i++) {
		scanf("%d",&x);
		Q.push(x);
	}
	int cnt=0;
	while(1) {
		int x=Q.top();
		Q.pop();
		int y=get_num(x);
		Q.push(y);
		ans[++cnt]=Q.top();
		if(Q.top()==1) {
			break;
		}
	}
	while(q--) {
		scanf("%d",&k);
		k=min(k,cnt);
		cout<<ans[k]<<endl;
	}
	return 0;
}