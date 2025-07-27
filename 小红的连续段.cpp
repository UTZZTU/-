#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<vector>
#include<random>
#include<string>
#include<cstdio>
#include<bitset>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<numeric>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>


#define endl "\n"
#define ll long long
#define int ll
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int invf[maxn];
int fac[maxn];

ll kpow(ll a, ll b) {
    int ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init(int n = maxn - 1) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++)fac[i] = fac[i - 1] * i % mod;
    invf[n] = kpow(fac[n], mod - 2);
    for (int i = n; i >= 1; i--)invf[i - 1] = invf[i] * i % mod;
}

int cal(int n, int m) {
    if (n < m || n < 0 || m < 0)return 0;
    return fac[n] * invf[m] % mod * invf[n - m] % mod;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(0);
    init();
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= x + y; i++) {
        int ans = 0;
        {
            int tx = (i + 1) / 2, ty = i - tx;
            ans += cal(x - 1, tx - 1) * cal(y - 1, ty - 1);
        }
        {
            int ty = (i + 1) / 2, tx = i - ty;
            ans += cal(x - 1, tx - 1) * cal(y - 1, ty - 1);
        }
        cout << ans % mod << endl;
    }
}

