#include<iostream>

using namespace std;
typedef long long LL;
const int N = 1e7 + 5, MOD = 1e9 + 7;
int prime[N], tot;
LL s[N], phi[N];
bool v[N];

//预处理 质数 和 欧拉函数
void pre(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            phi[i] = i - 1;
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot && i <= n / prime[j]; j++) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }

    s[1] = phi[1];
    for (int i = 2; i <= n; i++) s[i] = (s[i - 1] + 2 * phi[i]) % MOD;
}

int main() {
    int n;
    cin >> n;
    pre(n);
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + s[n / i] * i % MOD * i % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}