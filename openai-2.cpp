#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, a[N], fa[N], cnt[N]; // cnt数组用于记录每个集合中的数字有多少个素因子

int find(int x) {
    if (x != fa[x]) x = fa[x] = find(fa[x]);
    return x;
}

void solve() {
    unordered_map<int, int> mp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int num = a[i];
        for (int j = 2; j * j <= num; j++) {
            if (num % j == 0) {
                if (mp[j] != 0) {
                    int x = mp[j];
                    int eu = find(x), ev = find(i);
                    if (eu != ev) {
                        fa[ev] = eu;
                    }
                }
                while (num % j == 0) num /= j;
                mp[j] = i;
            }
        }
        if (num > 1) {
            if (mp[num] != 0) {
                int x = mp[num];
                int eu = find(x), ev = find(i);
                if (eu != ev) {
                    fa[ev] = eu;
                }
            }
            mp[num] = i;
        }
    }
    memset(cnt, 0, sizeof(cnt)); // 清空cnt数组
    for (int i = 1; i <= n; i++) {
        cnt[find(i)]++; // 统计每个集合中的数字有多少个素因子
    }
    
    vector<int> vec1, vec2;
    for (int i = 1; i <= n; i++) {
        if (cnt[find(i)] > 0) {
            vec1.push_back(a[i]); // 将属于同一个集合的数字放入vec1中
            cnt[find(i)] = 0; // 将计数清零，确保同一个集合中的数字只被处理一次
        } else {
            vec2.push_back(a[i]); // 其余数字放入vec2中
        }
    }
    
    if (vec1.empty() || vec2.empty()) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    
    cout << vec1.size() << " " << vec2.size() << endl;
    for (auto x : vec1) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : vec2) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}
