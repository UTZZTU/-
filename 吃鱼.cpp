#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 30000
#define MAX_M 60000
using namespace std;
int n;
int m;
struct Fish
{
    int w;
    int v;
    inline bool operator < (const Fish & x) const
    {
        if(w != x.w) return w < x.w;
        return v > x.v;
    }
};
Fish a[MAX_N + 5];
int ans;

int main()
{
    scanf("%d%d", &n, &m);
    int mid = 0;
    for(register int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i].w, &a[i].v);
        if(a[i].w & 1) ++mid;
    }
    sort(a + 1, a + n + 1);
    int i = 0, j = mid;
    while(i < mid && i < m)
    {
        ans += a[++i].v;
    }
    while(j < n && i + (j - mid + 1 << 1) <= m)
    {
        ans += a[++j].v;
    }
    while(i >= 2 && j < n && a[i].v + a[i - 1].v <= a[j + 1].v)
    {
        ans += a[++j].v - a[i--].v - a[i--].v;
    }
    if(i < mid && i + (j - mid << 1) < m)
    {
        ans += a[++i].v;
    }
    printf("%d", ans);
    return 0;
}