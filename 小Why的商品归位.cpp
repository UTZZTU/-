#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n,m,k,cha[N];

void solve()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int l,r;
        cin >> l >> r;
        cha[l]++,cha[r]--;
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        cha[i] += cha[i - 1];
        res = max(res,cha[i]);
    }
    cout << (res - 1)/k + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
}