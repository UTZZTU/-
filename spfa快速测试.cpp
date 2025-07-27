#include<bits/stdc++.h>

using namespace std;
const int N = 100010, M = 500010;
int head[N], ver[M], edge[M], Next[M], tot;
int t, r, s;
int d[N];
bool v[N];

void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

void read() {
    cin >> t >> r >> s;
    for (int i = 1; i <= r; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
}

void spfa() {
    for (int i = 1; i <= t; i++)
        d[i] = 0x3f3f3f3f;
    d[s] = 0;
    v[s] = true;
    deque<int> q;
    q.push_back(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                if (!v[y]) {
                    v[y] = true;
                    if (q.size() && d[y] < d[q.front()])
                        q.push_front(y);
                    else
                        q.push_back(y);
                }
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= t; i++)
    {
    	if(i!=1)
    	cout<<" ";
    	d[i] == 0x3f3f3f3f ? printf("2147483647") : printf("%d", d[i]);
	}
        
}

int main() {
    read();
    spfa();
    solve();
    return 0;
}
