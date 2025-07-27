#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 6;
int X = 2e6;
int a[N/4], b[N/4];
vector<int> v[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k; cin >> n >> k;

	int maxn = 0;
	int minn = 0;//所有离散化后的数据的最大值
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		x += X;
		minn = max(minn, x + k);
		v[x].push_back(x);
		v[x + k].push_back(x);
		maxn = max({ maxn, (int)(v[x].size()), (int)(v[x + k].size()) });
	}
	
	if (!k)
	{
		cout << maxn / 2 << endl;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i <= minn; i++)
	{
		if (v[i].size() == 0) continue;
		int m = (v[i].size());

		for (int j = 1; j <= m; j++)
			a[j] = a[j - 1] + (v[i][j - 1] == i);//前缀和

		int L = -1;//注意
		for (int j = 1; j <= m; j++)
		{
			L = max(L, a[j - 1] * 2 - j);//最大前缀
			ans = max(ans, L + j + 1 - a[j] + a[m] - a[j]);
		}
	}
	cout << ans << endl;

	return 0;
}
