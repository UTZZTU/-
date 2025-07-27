#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int primes[N], cnt;
bool vis[N];
int ans[N], sz;

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            vis[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool is_prime(int n) {
    if (n < N) return !vis[n];
    for (int i = 0; primes[i] <= n / primes[i]; i++) {
        if (n % primes[i] == 0) return false;
    }

    return true;
}

// cur表示当前要从哪个质数的下标开始枚举，prod表示要找的答案的部分质数乘积，s表示当前要分解约数和
void dfs(int cur, int prod, int s) {
    if (s == 1) {   // s == 1表示约数和已经分解完了，每一个Pi和αi已经找到
        ans[sz++] = prod;   // 答案就是各项Pi^αi的乘积
        return;
    }

    // 先特判一下是否存在一个Pi >= sqrt(s)，满足s == 1 + Pi -> Pi == s - 1
    // 如果满足，等价于Pi应该大于等于当前枚举的质数，即s - 1 >= primes[cur]，且Pi要是一个质数
    // 不return是因为Pi >= sqrt(s)只是我们枚举的一种情况而已，接下来还要枚举Pi < sqrt(s)的情况
    if (s - 1 >= primes[cur] && is_prime(s - 1)) ans[sz++] = prod * (s - 1);

    // 特判后，Pi的枚举范围就缩小到Pi^2 < s
    for (int i = cur; primes[i] < s / primes[i]; i++) {
        int t = primes[i];
        // j == 1 + Pi^1 + Pi^2 + ... + Pi^αi
        for (int j = 1 + primes[i]; j <= s; t *= primes[i], j += t) {
            if (s % j == 0) dfs(i + 1, prod * t, s / j);    // 只有j是s的某一项，即j可以整除s，即s % j == 0才可以继续往下搜
        }
    }
}

int main() {
    get_prime(N - 1);   // 筛质数，我们用到的质数小于sqrt(2e9)

    int n;
    while (~scanf("%d", &n)) {
        sz = 0;
        dfs(0, 1, n);

        printf("%d\n", sz);
        if (sz) {
            sort(ans, ans + sz);
            for (int i = 0; i < sz; i++) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
