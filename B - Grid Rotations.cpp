#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<vector<char> >c,ans;
int main()
{
	int n, m, q, add, x0 = 1, y0 = 1;
	scanf("%d%d", &n, &m);
	c.resize(n + 1);
	ans.resize(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		c[i].resize(m + 1);
		ans[i].resize(m + 1);
		getchar();
		for (int j = 1; j <= m; ++j)
			c[i][j] = getchar();
	}
	scanf("%d", &q);
	for (int i = 0, x, y; i < q; ++i)
	{
		scanf("%d%d", &x, &y);
		if (x0 <= x)x0 = x - x0 + 1;
		else x0 = n - x0 + x + 1;
		if (y0 <= y)y0 = y - y0 + 1;
		else y0 = m - y0 + y + 1;
	}
	if (q % 2)add = -1;
	else add = 1;
	for (int i = 0; i < n; ++i)
	{
		int x = (x0 + add * i + n - 1) % n + 1;
		for (int j = 0; j < m; ++j)
		{
			int y = (y0 + add * j + m - 1) % m + 1;
			ans[x][y] = c[i + 1][j + 1];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}