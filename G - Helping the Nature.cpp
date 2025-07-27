#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int a[N];
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		ll ans = 0;
		for (int i = n - 1; i >= 1; i--)
		{
			if (a[i] > a[i + 1]) ans += a[i] - a[i + 1];
		}
		if (a[1] - ans >= 0) cout << ans + a[n] << endl;
		else cout << ans + (ans - a[1]) * 2 + a[n] << endl;
	}
	return 0;
}
