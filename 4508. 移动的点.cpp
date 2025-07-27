#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 300010, Base = 2e9 + 1;
const LL Zero = 1e9;

int n, a, b;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    unordered_map<LL, int> hash1, hash2;

    while (n -- )
    {
        int vx, vy;
        scanf("%*d%d%d", &vx, &vy);
        hash1[vy - (LL)a * vx] ++ ;
        hash2[(vx + Zero) * Base + vy + Zero] ++ ;
    }

    LL res = 0;
    for (auto& [k, v]: hash1) res += v * (v - 1ll);
    for (auto& [k, v]: hash2) res -= v * (v - 1ll);

    printf("%lld\n", res);
    return 0;
}