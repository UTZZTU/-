#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 5e5 + 10;
struct IO {
	template <class T>
	IO operator>>(T &res) {
		res = 0;
		char ch;
		bool flag = false;
		while ((ch = getchar()) > '9' || ch < '0')	flag |= ch == '-';
		while (ch >= '0' && ch <= '9')	res = (res << 3) + (res << 1) + (ch ^ '0'), ch = getchar();
		if (flag)	res = ~res + 1;
		return *this;
	}
} cin;
int T, n, m, hd, ed;
int a[maxn], l[maxn], q[maxn];
ll f[maxn];
void solve ()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)    cin >> a[i], l[i] = 0;
    cin >> m;
    for (int i = 1, lt, rt; i <= m; ++i) {
        cin >> lt >> rt;
        l[rt] = max(l[rt], lt);
    }
    q[hd = ed = 1] = 0;
    a[++n] = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[q[hd]] + a[i];
        while (hd <= ed && f[q[ed]] > f[i])   --ed;
        q[++ed] = i;
        while (q[hd] < l[i])    ++hd;
    }
    printf("%lld\n", f[n]);
}
int main ()
{
    cin >> T;
    while (T--) solve();
    return 0;
}

