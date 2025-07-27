#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define xx first
#define yy second
#define endl "\n"
#define lowbit(x) x & (-x)
#define int long long
#define ull unsigned long long
#define pb push_back
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
#define LF(x) fixed << setprecision(x)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define Yshanqian ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e6 + 10, M = 1010, inf = 0x3f3f3f3f, mod = 1e9 + 7, P = 13331;
const double eps = 1e-8;
int n, m;
int s[N], a[N];
struct node
{
    int l, r;
    int sum, mx;
    int lazy;
} tr[N << 2];
void pushup(node &u, node &l, node &r)
{
    u.sum = l.sum + r.sum;
    u.mx = max(l.mx, r.mx);
}
void change1(int u, int x) //区间和
{
    tr[u].sum = x;
}
void change2(int u, int x) // 最大值
{
    tr[u].mx += x;
    tr[u].lazy += x;
}
void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void pushdown(int u)
{
    if (tr[u].lazy)
    {
        change2(u << 1, tr[u].lazy);
        change2(u << 1 | 1, tr[u].lazy);
        tr[u].lazy = 0;
    }
}
void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0, 0};
    if (l == r)
    {
        tr[u] = {l, r, a[l], s[l] - 2 * a[l], 0};
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
void modify(int u, int l, int r, int x, int id)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        if (id == 1)
            change1(u, x);
        else if (id == 2)
            change2(u, x);
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r, x, id);
    if (r > mid)
        modify(u << 1 | 1, l, r, x, id);
    pushup(u);
}
node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid)
        return query(u << 1, l, r);
    else if (l > mid)
        return query(u << 1 | 1, l, r);
    else
    {
        node res;
        auto left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
        pushup(res, left, right);
        return res;
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    build(1, 1, n);
    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            modify(1, l, l, 2 * a[l] - 2 * r, 2); // mx[i]=s[l]-2*a[l],先但单点修改
            modify(1, l, n, r - a[l], 2);         // 区间修改mx
            a[l] = r;
            modify(1, l, l, a[l], 1);
        }
        else
        {
            if (l > 1)
                cout << query(1, l + 1, r).mx - query(1, 1, l - 1).sum << endl;
            else
                cout << query(1, l + 1, r).mx << endl;
        }
    }
}
signed main()
{
    Yshanqian;
    int T;
    T = 1;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases)
    {
        // cout<<"Case #"<<cases<<": ";
        solve();
    }
    return 0;
}
