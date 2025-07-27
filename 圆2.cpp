#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2333

int n,m;
int f[MAXN][MAXN];

struct aa {
	int x,y,w,ls;
}b[MAXN<<1];
int t[MAXN];
int cnt;

void jb(int x,int y,int w) {
	cnt ++;
	b[cnt] = {x,y,w,t[x]};
	t[x] = cnt;
}

signed main() {
	cin >> n >> m;
	int ss = 0;
	for(int i = 1; i <= m; i ++) {
		int x,y,w;
		cin >> x >> y >> w;
		jb(x,y,w);
		jb(y,x,w);
		ss += w;
	}
	for(int len = 1; len <= n; len ++) {
		for(int l = 1; l <= n-len+1; l ++)
		{
			int r = l+len-1;
			f[l][r] = f[l+1][r];
			for(int i = t[l]; i != 0; i = b[i].ls) {
				int y = b[i].y;
				if(y <= l || y > r) continue;
				f[l][r] = max(f[l][r],f[l+1][y-1]+f[y+1][r]+b[i].w);
			}
		}
	}
	cout<<ss-f[1][n];
	return 0;
}