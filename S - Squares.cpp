#include <stdio.h>
#include <string.h>
#define maxn 15
// 分开储存
int r[maxn][maxn];
int c[maxn][maxn];
int main() {
	int n;
	int kase = 0;
	while (scanf("%d", &n) != EOF) {
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
        // 注意格式!!!
		if (kase > 0) {
			printf("\n");
			printf("**********************************\n\n");
		}
		int len;
		scanf("%d", &len);
		for (int k = 0; k < len; k++) {
			char ch;
			int i, j;
			getchar();
			scanf("%c", &ch);
			if (ch == 'H') {
				scanf("%d%d", &i, &j);
                // 有边则设置为1
				r[i][j] = 1;
			} else if (ch == 'V') {
				scanf("%d%d", &i, &j);
				c[i][j] = 1;
			}
		}
		int flag = 1;
		int all[n];
		memset(all, 0, sizeof(all));
		printf("Problem #%d\n\n", ++kase);
		int num = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n * (n - i); j++) {
				flag = 1;
				for (int k = 0; k < i; k++) {
                    // 关键代码,判断边是否符合条件.
					if (r[(j - 1) / n + 1][(j - 1) % n + 1 + k] != 1 || r[(j - 1) / n + 1 + i][(j - 1) % n + 1 + k] != 1|| c[(j - 1) % n + 1][(j - 1) / n + 1 + k] != 1 ||c[(j - 1) % n + 1 + i][(j - 1) / n + 1 + k] != 1) {
						flag = 0;
						break;
					}
				}
				if (flag == 1) {
					all[i]++;
				}
			}
			if (all[i] > 0) {
				printf("%d square (s) of size %d\n", all[i], i);
				num++;
			}
		}
		if (num == 0) {
			printf("No completed squares can be found.\n");
		}
	}
	return 0;
}
