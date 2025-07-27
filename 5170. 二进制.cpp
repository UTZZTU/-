#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000010, MOD = 1e6 + 3;

int n, m;
int s[N], p[N], v[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (LL)res * a % MOD;
        a = (LL)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    int fa = 1, fb = 1, fab = 1;
    for (int i = 1; i <= a; i ++ ) fa = (LL)fa * i % MOD;
    for (int i = 1; i <= b; i ++ ) fb = (LL)fb * i % MOD;
    for (int i = 1; i <= a - b; i ++ ) fab = (LL)fab * i % MOD;

    return (LL)fa * qmi(fb, MOD - 2) * qmi(fab, MOD - 2) % MOD;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) p[i] = i, v[i] = -1;
    for (int i = 0; i < n - m + 1; i ++ ) scanf("%d", &s[i]);

    for (int i = 0, j = m; i < n - m; i ++, j ++ )
        if (s[i] == s[i + 1])
            p[find(j)] = find(i);

    for (int i = 0, j = m; i < n - m; i ++, j ++ )
        if (s[i] > s[i + 1])
            v[find(i)] = 1, v[find(j)] = 0;
        else if (s[i] < s[i + 1])
            v[find(i)] = 0, v[find(j)] = 1;

    int c0 = 0, c1 = 0;
    for (int i = 0; i < m; i ++ )
    {
        int t = v[find(i)];
        if (t == 0) c0 ++ ;
        else if (t == 1) c1 ++ ;
    }

    printf("%d\n", C(m - c0 - c1, s[0] - c1));
    return 0;
}