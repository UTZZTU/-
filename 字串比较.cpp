#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false), cin.tie(0);
#define int long long
#define endl "\n"
#define pi acos(-1)
typedef pair<int, int> pii;
const double eps = 1e-6;
const int N = 1e6 + 10, M = 1010, INF = 1e18;
const int mod = 998244353;
int a[N], b[N];
const int p = 131;
int h[N];
int geta(int l, int r)
{
    return a[r] - a[l - 1] * h[r - l + 1];
}
int getb(int l, int r)
{
    return b[r] - b[l - 1] * h[r - l + 1];
}
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;

    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;

    a[0] = 1;
    h[0] = 1;
    for (int i = 1; i < s.size(); i++)
    {
        h[i] = h[i - 1] * p;
        a[i] = a[i - 1] * p + s[i];
    }
    b[0] = 1;
    for (int i = 1; i < t.size(); i++)
    {
        b[i] = b[i - 1] * p + t[i];
    }

    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int x = geta(l1, r1);
        int y = getb(l2, r2);

        if (x == y)
        {
            cout << '=' << endl;
            continue;
        }
        int l = 0, r = r1 - l1 + 1;
        int ans = 0;

        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            int L1 = l1 + mid-1, L2 = l2 + mid-1;
            int x = geta(l1, L1);
            int y = getb(l2, L2);
            if (x == y)
                l = mid;
            else
                r = mid - 1;
        }

        l1 += l;
        l2 += l;
        if (s[l1] > t[l2])
            cout << '>' << endl;
        else if (s[l1] < t[l2])
            cout << '<' << endl;
        else
            cout << '=' << endl;
    }
}
signed main()
{
    ios;
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        // cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}