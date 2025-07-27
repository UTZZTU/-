#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 66;
int a[3][MAXN];
int size[3];
int m[MAXN];
 
bool DFS(int n, int s, int e, int mid) {
    if (n <= 0) return true;
    if (m[n] == mid) return false;
    if (m[n] == s) {
        return DFS(n - 1, s, mid, e);
    } else {
        return DFS(n - 1, mid, e, s);
    }
}
 
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < 3; i++) {
            scanf("%d", &size[i]);
            for (int j = 0; j < size[i]; j++) {
                scanf("%d", &a[i][j]);
                m[a[i][j]] = i;
            }
        }
        if (DFS(N, 0, 2, 1)) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}