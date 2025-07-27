#include <bits/stdc++.h>
#define N 1000005
#define M 21
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sc(t) scanf("%d", &t)
#define scl(t) scanf("%lld", &t)
#define scf(t) scanf("%lf", &t)
#define lowbit(x) (x & -x)
#define x first
#define y second
using namespace std;
using i64 = long long;
// using i128 = __int128;
using ui64 = unsigned long long;
using pii = pair<int, int>;
constexpr int mod = 1e9 + 7;
constexpr int MOD = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr double eps = 1e-6;
constexpr double pi = 3.1415926535897932384;

struct Manacher
{
    string s;
    string b;
    int len;
    vector<int> p;
    Manacher(string& s) : s(s) 
    {
        init();
        manacher();
    }
    void init()
    {
        b = "$";
        int k = 1;
        for(int i = 0; i < s.size(); i ++ ) b += "#", b += s[i], k += 2;
        b += "#^";
        len = k + 2;
        p.assign(len, 0);
    }
    void manacher()
    {
        int mr = 0, mid;
        for (int i = 1; i < len; i ++ )
        {
            if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
            else p[i] = 1;
            while (b[i - p[i]] == b[i + p[i]]) p[i] ++ ;
            if (i + p[i] > mr)
            {
                mr = i + p[i];
                mid = i;
            }
        }
    }
    bool check(int idx)
    {
        int mid = idx + 2;
        return p[mid] == mid;
    }
};

int suf[N];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cout << fixed << setprecision(10);
    int T = 1;
    // cin >> T;
    while(T -- )
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Manacher S1(s1), S2(s2);
        for(int i = 0, j = m - 1; i < n - 1 && j >= 0; i ++, j -- )
        {
            if(s1[i] != s2[j]) break;
            else
            {
                if(S1.check(i))
                {
                    suf[j] = i + 1;
                }
            }
        }
        for(int i = m - 1; i >= 0; i -- ) suf[i] = max(suf[i], suf[i + 1]);
        int ans = -1;
        for(int i = 0, j = n - 1; i < m - 1 && j >= 0; i ++ , j -- )
        {
            if(s2[i] != s1[j]) break;
            else
            {
                if(S2.check(i))
                {
                    int tmp = min(n - i - 1, m - i - 1);
                    if(tmp && suf[m - tmp])
                    {
                        ans = max(ans, (i + 1 + suf[m - tmp]) * 2);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
