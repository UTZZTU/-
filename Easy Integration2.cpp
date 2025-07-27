#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e6 + 5;
ll qkpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll getInv(ll a) { return qkpow(a, mod - 2); }  //求一个数的逆元
ll fac[N * 2];
int main() {
    fac[0] = 1;
    for (int i = 1; i < N * 2; ++i) fac[i] = fac[i - 1] * i % mod;
    int n;
    while (cin >> n)
        cout << fac[n] * fac[n] %mod * getInv(fac[2 * n + 1]) % mod << endl;
    return 0;
}