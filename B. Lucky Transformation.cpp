#include <cstdio>
#include <algorithm>

const int N = 100009;

int n, k, flag;
int d[N];

int main() {
    scanf("%d%d", &n, &k);
    flag = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    for (int i = 1; i <= n; i++) d[i] = c - '0', c = getchar(); 
    for (int i = 1; i <= n && k; i++) {
        if (d[i] == 4 && d[i + 1] == 7 && d[i + 2] == 7 && (i & 1)) k %= 2;
        if (d[i] == 4 && d[i + 1] == 7 && k) {
            if (i & 1) d[i + 1] = 4;
            else d[i] = 7;
            i -= 2, k--;
        }
    }
    for (int i = 1; i <= n; i++) putchar(d[i] + '0');
    return 0;
}