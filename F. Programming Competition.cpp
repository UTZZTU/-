#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 4e5 + 10;
int h[N], e[M], ne[M], idx;
int sz[N];
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void init(int u)
{
	sz[u] = 1;
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];
        init(v);
		sz[u] += sz[v];
	}
}
int dfs(int u, int k)
{
	int tot = 0, mx = -1;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int v = e[i];
		tot += sz[v];
		if (mx == -1 || sz[mx] < sz[v])mx = v;
	}
	if (tot == 0)return 0;
	if (sz[mx] - k <= tot - sz[mx])
		return (tot - k) / 2;
	int add = tot - sz[mx];
	return add + dfs(mx, max(0, add + k - 1));
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(h, -1, sizeof h);
		idx = 0;
		for (int i = 2; i <= n; i++)
		{
			int p;
			cin >> p;
			add(p, i);
		}
		init(1);
		cout << dfs(1, 0) << endl;
	}
}
