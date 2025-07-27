#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int N = 200010, P = 131;

int n, m;
char s1[N], s2[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

void solve()
{
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1), m = strlen(s2 + 1);

    if (m < n)
    {
        cout << 0 << "\n";
        return;
    }

    p[0] = 1;
    for (int i = 1; i <= m; i ++ )
    {
        h[i] = h[i - 1] * P + s2[i];
        p[i] = p[i - 1] * P;
    }

    vector<int> cnt1(26);
    for (int i = 1; i <= n; i ++ )
        cnt1[s1[i] - 'a'] ++ ;

    vector<int> cnt2(26);
    for (int i = 1; i <= n; i ++ )
        cnt2[s2[i] - 'a'] ++ ;

    set<ULL> S;
    int res = 0;
    if (cnt1 == cnt2) res ++ , S.insert(get(1, n));
    for (int i = n + 1; i <= m; i ++ )
    {
        cnt2[s2[i] - 'a'] ++ ;
        cnt2[s2[i - n] - 'a'] -- ;
        if (cnt1 == cnt2)
            if (!S.count(get(i - n + 1, i)))
            {
                res ++ ;
                S.insert(get(i - n + 1, i));
            }
    }

    printf("%d\n", res);
}

int main()
{ 
    int T = 1;

    while (T -- ) solve();

    return 0;
}