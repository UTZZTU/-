#include <bits/stdc++.h>
using namespace std;
int n, k, a[110][110];
map<string, int> name;
string s, x[110];
int main() {
    cin >> k >> n;
    for (int i = 1;i <= n; i++) for (int j = 1;j <= n; j++) a[i][j] = 2;
    for (int i = 1;i <= n; i++) cin >> s, name[s] = i;
    int A = 0;
    while (k--) {
        A = 1;
        for (int i = 1;i <= n; i++) {
            cin >> x[i];
            if (x[i] < x[i - 1]) A = i;
            for (int j = 1;j < A; j++)
                a[name[x[i]]][name[x[j]]] = 1, a[name[x[j]]][name[x[i]]] = 0;
        }
    }
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j <= n; j++) {
            if (i == j) {printf("B"); continue;}
            if (a[i][j] != 2) printf("%d", a[i][j]);
            else printf("?");
        }
        puts("");
    }
    return 0;
}