#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 并查集
class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

int main() {
    int n,t;
    cin >> t;
    {
        while(t--)
        {
            cin>>n;
            vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 使用并查集找出具有共同素因子的数字
    UnionFind uf(n);
    unordered_map<int, int> lastPrimeIndex;
    for (int i = 1; i <= n; ++i) {
        int num = a[i];
        for (int j = 2; j * j <= num; ++j) {
            if (num % j == 0) {
                if (lastPrimeIndex.find(j) != lastPrimeIndex.end()) {
                    uf.merge(lastPrimeIndex[j], i);
                }
                while (num % j == 0) {
                    num /= j;
                }
                lastPrimeIndex[j] = i;
            }
        }
        if (num > 1) {
            if (lastPrimeIndex.find(num) != lastPrimeIndex.end()) {
                uf.merge(lastPrimeIndex[num], i);
            }
            lastPrimeIndex[num] = i;
        }
    }

    // 将数字分配到两个数组中
    vector<int> b, c;
    int eu=uf.find(1);
    for (int i = 1; i <= n; ++i) {
        if (uf.find(i) == eu) {
            b.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }

    // 输出结果
    if (b.empty() || c.empty()) {
        cout << -1 << " " << -1 << endl;
    } else {
        cout << b.size() << " " << c.size() << endl;
        for (int num : b) {
            cout << num << " ";
        }
        cout << endl;
        for (int num : c) {
            cout << num << " ";
        }
        cout << endl;
    }
        }
    }

    return 0;
}
