#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2000010;

int n, m;
int cnt[N], s[N];

LL C(int a, int b)
{
    LL res = 1;
    for (int i = a, j = 1; j <= b; i --, j ++ )
        res = res * i / j;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ )
    {
        int p;
        scanf("%d", &p);
        cnt[p] ++, cnt[p + m] ++ ;
    }
    for (int i = 1; i < m * 2; i ++ )
        s[i] = s[i - 1] + cnt[i];

    LL res = C(n, 3);
    int len = (m - 1) / 2;
    for (int i = 0; i < m; i ++ )
    {
        int x = s[i + len] - s[i];
        int y = cnt[i];
        res -= C(y, 3) + C(y, 2) * x + y * C(x, 2);
    }

    if (m % 2 == 0)
    {
        for (int i = 0; i < m; i ++ )
        {
            res -= (LL)cnt[i] * cnt[i + m / 2] * (s[i + m / 2 - 1] - s[i]);
            res -= cnt[i] * C(cnt[i + m / 2], 2);
        }
    }

    printf("%lld\n", res);
    return 0;
}