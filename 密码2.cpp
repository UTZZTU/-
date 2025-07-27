

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int N = 200;
int a[N], cycle[N];
char s[N + 1], ans[N + 1];

int main()
{
    int n, k;
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        // 计算循环数组
        for(int i = 0; i < n; i++) {
            int cnt = 0, key = i;
            while(a[key] != i) cnt++, key = a[key];
            cycle[i] = cnt + 1;
        }

        while(~scanf("%d", &k) && k) {
            getchar();
            gets(s);
            for(int i = strlen(s); i < n; i++)
                s[i] = ' ';

            for(int i = 0; i < n; i++) {
                int t = i, ti = i;
                int times = k % cycle[i];			// 对字符s[i]，进行times次变换
                for(int j = 0; j < times; j++) {
                    t = a[ti];
                    ti = t;
                }
                ans[t] = s[i];
            }

            ans[n] = '\0';

            printf("%s\n", ans);
        }
        printf("\n");
    }

    return 0;
}
