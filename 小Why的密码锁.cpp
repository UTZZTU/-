#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

const int N = 1e6 + 10,P = 131;

int n,m,k;
char s[N];

LL h[N],p[N];

LL get(int l,int r)
{
    return h[r] - h[l - 1]*p[r - l + 1];
}

//1231231

void solve()
{
    map<LL,LL> cnt;
    map<LL,LL> last;
    cin >> n >> m >> k >> s + 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1]*P;
        h[i] = h[i - 1]*P + s[i];
    }

    for(int i = 1; i <= n; i++)
    {
        if(i + m - 1 > n) break;
        LL hashv = get(i,i + m - 1);
        if(last[hashv] + m - 1 >= i && last[hashv]) continue; //如果上一个一样的子串位置重叠 那么就不合法
        last[hashv] = i; //更新这个子串的最新位置
        cnt[hashv]++; //记录这个子串的出现次数
    }

    LL res = 0;
    for(auto tt : cnt)
    {
        if(tt.second == k) res++; //找到有几种子串出现次数等于k
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
}