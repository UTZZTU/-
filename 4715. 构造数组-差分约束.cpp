#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010, M = N * 3;

int n;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa()
{
    queue<int> q;
    q.push(0);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main()
{
    string s;
    cin >> n >> s;

    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ ) add(0, i, 1);
    for (int i = 0; i < n - 1; i ++ )
    {
        char c = s[i];
        int a = i + 1, b = i + 2;
        if (c == '=') add(a, b, 0), add(b, a, 0);
        else if (c == '>') add(b, a, 1);
        else add(a, b, 1);
    }

    spfa();

    for (int i = 1; i <= n; i ++ )
        cout << dist[i] << ' ';

    return 0;
}