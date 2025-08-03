#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int ,int > PII;

int const N = 2000010, mol = 1e9 + 7;

LL n, m, k;
LL a[N], b[N], pre[N], sub[N];
void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	sub[n + 1] = 0;
	for(int i = n; i >= 1; i--) sub[i] = sub[i + 1] + b[i];
	vector<LL> mx1(n + 2, -1e18);
	vector<LL> mx2(n + 2, -1e18);
	vector<LL> mx3(n + 2, -1e18);
	vector<LL> mx4(n + 2, -1e18);
	for(int i = 1; i <= n; i++){
		mx1[i] = max(mx1[i - 1], b[i] - a[i]);
	}
	for(int i = 1; i <= n; i++){
		mx3[i] = max(mx3[i - 1], b[i]);
	}
	for(int i = n; i >= 1; i--){
		mx2[i] = max(mx2[i + 1], a[i] - b[i]);
	}
	for(int i = n; i >= 1; i--){
		mx4[i] = max(mx4[i + 1], a[i]);
	}
	LL ans = -1e18;
	for(int i = 1; i <= n; i++){
		LL sum = pre[i] + sub[i];
		ans = max(ans, sum + mx1[i - 1] + mx2[i + 1]);
		ans = max(ans, sum + mx3[i] - b[i]);
		ans = max(ans, sum + mx4[i] - a[i]);
	}
	cout << ans << "\n";
}
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- ) solve();
}
