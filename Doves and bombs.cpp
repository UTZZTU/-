#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;
const int maxn = 111111;
int pre[maxn], bccno[maxn], bcc_cnt, iscut[maxn], dfs_clock;
vector<int> G[maxn], bcc[maxn];
struct edge{
	int u, v;
	edge(int u, int v) : u(u), v(v){}
};
stack<edge> S;
int n, m;
struct node{
	int pos, val;
	bool operator < (const node &a)const{
		if (val == a.val)
			return pos < a.pos;
		return val > a.val;
	}
}T[maxn];
int dfs(int u, int fa){
	int lowu = pre[u] = ++dfs_clock;
	int chd = 0;
	for (int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		edge e = edge(u, v);
		if (!pre[v]){
			S.push(e);
			chd += 1;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u]){
				iscut[u] = 1;
				bcc_cnt += 1; bcc[bcc_cnt].clear();
				for(;;){
					edge x = S.top(); S.pop();
					if (bccno[x.u] != bcc_cnt){
						bcc[bcc_cnt].push_back(x.u); bccno[x.u] = bcc_cnt;
					}
					if (bccno[x.v] != bcc_cnt){
						bcc[bcc_cnt].push_back(x.v); bccno[x.v] = bcc_cnt;
					}
					if (x.u == u && x.v == v) break;
				}
			}
		}
		else if (pre[v] < pre[u] && v != fa){
			S.push(e);
			lowu = min(lowu, pre[v]);
		}
	}
	if (fa < 0 && chd == 1) iscut[u] = 0;
	return lowu;
}
set<int> ss;
void find_bcc(int n){
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizeof(bccno));
	dfs_clock = bcc_cnt = 0;
	ss.clear();
	for (int i = 0; i < n; i++)
		if (!pre[i]) dfs(2, -1);
	for (int i = 0; i < n; i++){
		if (iscut[i]){
			for (int j = 0; j < G[i].size(); j++){
				int v = G[i][j];
				ss.insert(bccno[v]);
			}
			T[i].pos = i; T[i].val = ss.size();
			ss.clear();
		}
		else{
			T[i].pos = i;
			T[i].val = 1;
		}
	}
	sort(T, T + n);
	for (int i = 0; i < m; i++)
		printf("%d %d\n", T[i].pos, T[i].val);
	printf("\n");
}
int main(){
	while (~scanf("%d%d", &n, &m)){
		if (!n && !m) break; 
		int x, y;
		for (int i = 0; i <= n; i++)
			G[i].clear();
		while(~scanf("%d%d", &x, &y)){
			if (x == -1 && y == -1) break;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		find_bcc(n);
	}
	return 0;
}