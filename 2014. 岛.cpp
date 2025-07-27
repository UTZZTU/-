#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
int h[N];
PII q[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);

    n = unique(h + 1, h + n + 1) - h - 1;  // 判重
    h[n + 1] = 0;  // 后续代码可能会用到第n + 1个位置，需要把第n + 1个位置清空

    for (int i = 1; i <= n; i ++ ) q[i] = {h[i], i};

    sort(q + 1, q + n + 1);

    int res = 1, cnt = 1;
    for (int i = 1; i <= n; i ++ )
    {
        int k = q[i].y;
        if (h[k - 1] < h[k] && h[k + 1] < h[k]) cnt -- ;
        else if (h[k - 1] > h[k] && h[k + 1] > h[k]) cnt ++ ;

        if (q[i].x != q[i + 1].x)
            res = max(res, cnt);
    }

    printf("%d\n", res);

    return 0;
}