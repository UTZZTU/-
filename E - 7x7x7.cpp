//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/math>

using namespace std;
// using namespace atcoder;

// #define _GLIBCXX_DEBUG

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                                \
    cerr << #v << endl;                             \
    for (int iv = 0; iv < v.size(); iv++) {         \
        for (int jv = 0; jv < v[iv].size(); jv++) { \
            cerr << v[iv][jv] << " ";               \
        }                                           \
        cerr << endl;                               \
    }
typedef long long ll;
// #define int ll

#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pll pair<ll, ll>
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (int)(n); i > 0; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(), c.end()
void YES(bool t = true) {
    cout << (t ? "YES" : "NO") << endl;
}
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << endl; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << endl; }
void NO(bool t = true) { cout << (t ? "NO" : "YES") << endl; }
void No(bool t = true) { cout << (t ? "No" : "Yes") << endl; }
void no(bool t = true) { cout << (t ? "no" : "yes") << endl; }
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
vi dx2 = {1, 1, 0, -1, -1, -1, 0, 1}, dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
        cerr << fixed << setprecision(25);
    }
} setup_io;
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
// #define mp make_pair
// #define endl '\n'

struct dice {
    mt19937 mt;
    dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    // [0, x)の一様乱数
    ll operator()(ll x) { return this->operator()(0, x); }
    // [x, y)の一様乱数
    ll operator()(ll x, ll y) {
        uniform_int_distribution<ll> dist(x, y - 1);
        return dist(mt);
    }
    vl operator()(int n, ll x, ll y) {
        vl res(n);
        for (int i = 0; i < n; i++)
            res[i] = this->operator()(x, y);
        return res;
    }
} rnd;

std::random_device seed_gen;
std::mt19937 engine(seed_gen());

using ull = unsigned long long;
const ull MASK30 = (1ULL << 30) - 1;
const ull MASK31 = (1ULL << 31) - 1;
const ull M = (1ULL << 61) - 1;
const ull B = rnd(129, M);
const ull POSITIVIZER = M * ((1ULL << 3) - 1);

class RollingHash {
  public:
    vector<ull> hash;
    vector<ull> Bpower;

    RollingHash(string s = "") {
        int n = s.size();
        hash.resize(n + 1);
        Bpower.resize(n + 1);
        Bpower[0] = 1;
        hash[0] = 0;

        for (int i = 0; i < n; i++) {
            hash[i + 1] = _calc_mod(_mul(hash[i], B) + (ull)s[i]);
            Bpower[i + 1] = _calc_mod(_mul(Bpower[i], B));
        }
    }

    // S[l, r)
    ull part(int l, int r) {
        return _calc_mod(hash[r] + POSITIVIZER - _mul(hash[l], Bpower[r - l]));
    }

    ull _mul(ull a, ull b) {
        ull au = a >> 31;
        ull ad = a & MASK31;
        ull bu = b >> 31;
        ull bd = b & MASK31;
        ull mid = ad * bu + au * bd;
        ull midu = mid >> 30;
        ull midd = mid & MASK30;
        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }

    ull _calc_mod(ull val) {
        val = (val & M) + (val >> 61);
        if (val >= M) val -= M;
        return val;
    }
};

int calc_v3(int a1, int b1, int c1, int a2, int b2, int c2, int a3, int b3, int c3) {
    int a_max = max({a1, a2, a3}), a_min = min({a1 + 7, a2 + 7, a3 + 7});
    int b_max = max({b1, b2, b3}), b_min = min({b1 + 7, b2 + 7, b3 + 7});
    int c_max = max({c1, c2, c3}), c_min = min({c1 + 7, c2 + 7, c3 + 7});

    return max(0, a_min - a_max) * max(0, b_min - b_max) * max(0, c_min - c_max);
}
int calc_v2(int a1, int b1, int c1, int a2, int b2, int c2) {
    int a_max = max(a1, a2), a_min = min(a1 + 7, a2 + 7);
    int b_max = max(b1, b2), b_min = min(b1 + 7, b2 + 7);
    int c_max = max(c1, c2), c_min = min(c1 + 7, c2 + 7);

    return max(0, a_min - a_max) * max(0, b_min - b_max) * max(0, c_min - c_max);
}

signed main() {
    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;

    int a1 = 50, b1 = 50, c1 = 50;

    for (int a2 = 50; a2 <= 64; a2++) {
        for (int b2 = 50; b2 <= 64; b2++) {
            for (int c2 = 50; c2 <= 64; c2++) {
                for (int a3 = 43; a3 <= 64; a3++) {
                    for (int b3 = 43; b3 <= 64; b3++) {
                        for (int c3 = 43; c3 <= 64; c3++) {
                            int V3 = calc_v3(a1, b1, c1, a2, b2, c2, a3, b3, c3);

                            int V2 = calc_v2(a1, b1, c1, a2, b2, c2) + calc_v2(a2, b2, c2, a3, b3, c3) + calc_v2(a3, b3, c3, a1, b1, c1);
                            V2 -= 3 * V3;
                            int V1 = 7 * 7 * 7 * 3 - 3 * V3 - 2 * V2;
                            // DEBUG(V1);
                            // DEBUG(V2);
                            // DEBUG(V3);
                            // return 0;
                            if (v1 == V1 and v2 == V2 and v3 == V3) {
                                Yes();
                                cout << a1 << " " << b1 << " " << c1 << " " << a2 << " " << b2 << " " << c2 << " " << a3 << " " << b3 << " " << c3 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    No();
}
