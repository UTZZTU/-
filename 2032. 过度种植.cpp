#include <iostream>
using namespace std;
int n;
typedef struct pla
{
    int x1, y1, x2, y2;
}plc;

bool mul(plc &a, plc b)
{
    if (a.x1 >= b.x2 || a.x2 <= b.x1 || a.y1 <= b.y2 || a.y2 >= b.y1) return false;
    int x1 = max(a.x1, b.x1), y1 = min(a.y1, b.y1);
    int x2 = min(a.x2, b.x2), y2 = max(a.y2, b.y2);
    a = {x1, y1, x2, y2};
    return true;
}

int count(plc a)
{
    return (a.x2 - a.x1) * (a.y1 - a.y2);
}

plc a[15];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

    int ans = 0;
    for (int i = 1; i < (1 << n); i ++ )
    {
        plc res;
        int cnt = 0; bool st = false, has_n = true;
        for (int j = 0; j < n; j ++ )
        {
            if ((i >> j) & 1)
            {
                if (!st) res = a[j], st = true, cnt ++ ;
                else
                {
                    if (!mul(res, a[j])){has_n = false; break;};
                    cnt ++;
                }
            }
        }
        if (!has_n) continue;
        if (cnt & 1) ans += count(res);
        else ans -= count(res);
    }
    cout << ans << endl;
    return 0;
}