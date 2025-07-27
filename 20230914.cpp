#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <queue>
#define buff ios::sync_with_stdio(false)
#define clean(a, x, n, l) memset(a, x, n * sizeof(l))
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MAX = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e6 + 10;
double Pi = acos(-1);

void solve()
{
    double n, ax, ay, bx, by, cx, cy, dx, dy, ex, ey;
    cin >> n;
    if(n == 0)
    {
        printf("A: 0.00 0.00\n");
        printf("B: 0.00 0.00\n");
        printf("C: 0.00 0.00\n");
        printf("D: 0.00 0.00\n");
        printf("E: 0.00 0.00\n");
        return;
    }
    ex = 0, ey = n * sin(72.0 * Pi / 180.0);
    ax = n * sin(18.0 * Pi / 180.0) + n, ay = 0;
    double chang = ax / (cos(18.0 * Pi / 180.0));
    bx = chang * cos(54.0 * Pi / 180.0), by = chang * sin(54.0 * Pi / 180.0) + chang * sin(18.0 * Pi / 180.0);
    cx = -bx, cy = by;
    dx = -ax, dy = ay;
    printf("A: %.2lf %.2lf\n", ax, ay);
    printf("B: %.2lf %.2lf\n", bx, -by);
    printf("C: %.2lf %.2lf\n", cx, -cy);
    printf("D: %.2lf %.2lf\n", dx, dy);
    printf("E: %.2lf %.2lf\n", ex, ey);
}

int main()
{
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}
