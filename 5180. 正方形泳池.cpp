#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
PII tr[N];

int work()
{
    sort(tr, tr + m);
    int res = 0;
    for (int i = 0; i < m; i ++ )
    {
        int up = n + 1, down = 0;
        for (int j = i + 1; j < m; j ++ )
        {
            // if (tr[j].x == tr[i].x) continue;
            if (tr[j].x - tr[i].x > up - down) break;
            res = max(res, tr[j].x - tr[i].x - 1);
            if (tr[j].y >= tr[i].y) up = min(up, tr[j].y);
            if (tr[j].y <= tr[i].y) down = max(down, tr[j].y);
        }
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++ ) scanf("%d%d", &tr[i].x, &tr[i].y);
    tr[m ++ ] = {0, 0};
    tr[m ++ ] = {0, n + 1};
    tr[m ++ ] = {n + 1, 0};
    tr[m ++ ] = {n + 1, n + 1};

    int res = work();
     for (int i = 0; i < m; i ++ ) swap(tr[i].x, tr[i].y);

    printf("%d\n", max(res, work()));
    return 0;
}