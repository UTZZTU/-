#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
ll n,m;
ll h[N],e[N],ne[N],idx,w[N];
ll a[N],b[N],c[N];
ll dist[N];
ll bian[N];
bool st[N];
map<ll,ll>mp;

void add(int a,int b,int c) {
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}

void spfa(int s) {
	queue<int>q;
	memset(dist,0x3f,sizeof dist);
	memset(bian,0x3f,sizeof bian);
	q.push(s);
	dist[s]=0;
	bian[s]=0;
	while(q.size()) {
		int t=q.front();
		q.pop();
		if(st[t])continue;
		st[t]=true;
		for(int i=h[t]; ~i; i=ne[i]) {
			int j=e[i];
			int W=w[i];
			bian[j]=min(bian[j],bian[t]+1);
			if(dist[j]>dist[t]+W) {
				dist[j]=dist[t]+W;
				q.push(j);
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(h,-1,sizeof h);
	bool f=0;
	for(int i=1; i<=m; i++) {
		cin>>a[i]>>b[i]>>c[i];
	}
	if(m==n-1) {
		f=1;
	}
	for(int i=1; i<=m; i++) {
		if(!f) {
			add(a[i],b[i],1);
			add(b[i],a[i],1);
		} else {
			if(a[i]!=1&&b[i]!=1) {
				add(a[i],b[i],1);
				add(b[i],a[i],1);
			} else {
				add(a[i],b[i],c[i]);
				add(b[i],a[i],c[i]);
			}
		}
	}
	spfa(1);
	if(bian[n]<m) {
		dist[n]=bian[n];
	}
	cout<<dist[n];
	return 0;
}