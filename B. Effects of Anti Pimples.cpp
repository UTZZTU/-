#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 1e5 + 10, mod = 998244353;
int n;
int a[N], b[N];

signed main()
{
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j += i)
        {
            b[i] = max(b[i], a[j]);
        }
    }
    sort(b + 1, b + n + 1);
    ll base = 1;
    ll tot = 0;
    for(int i = 1;i <= n;i++)
    {
        tot = (tot + b[i] * base) % mod;
        base = base * 2 % mod;
    }
    cout << tot;
    return 0;
}
