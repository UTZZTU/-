#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300010, INF = 1e9;

int n;
int x[N], y[N];

int main()
{
    scanf("%d", &n);
    int u = -INF, d = INF, l = INF, r = -INF;
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d%d", &x[i], &y[i]);
        u = max(u, y[i]), d = min(d, y[i]);
        l = min(l, x[i]), r = max(r, x[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i ++ )
        res = max(res, max(u - y[i], y[i] - d) + max(r - x[i], x[i] - l));
    printf("%d ", res * 2);
    for (int i = 4; i <= n; i ++ )
        printf("%d ", 2 * (u - d + r - l));

    return 0;
}