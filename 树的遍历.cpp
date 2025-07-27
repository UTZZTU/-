#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#include <time.h>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e4;
const ll maxm = 1e7;
const int mod = 1000000009;
const int INF = 0x3f3f3f;
const ll inf = 1e14 + 5;
const db eps = 1e-9;
int qian[maxn], zhong[maxn], hou[maxn];
int n;

void dfs(int root, int start, int endd, int index) {
    if (start>endd)  return;
    int i=start;
    while(i<endd&&zhong[i]!=hou[root])  i++;
    qian[index]=hou[root];
    dfs(root-1-endd+i, start, i-1, 2*index+1);
    dfs(root-1, i+1, endd, 2*index+2);
}
void solve() {
    scanf("%d", &n);
    memset(qian, 0, sizeof(qian));
    memset(hou, 0, sizeof(hou));
    memset(zhong ,0, sizeof(zhong));
    for (int i = 0; i < n; i++) {
        scanf("%d", hou+i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", zhong+i);
    }
    dfs(n-1, 0, n-1, 0);
    int cnt=0;
    for (int i = 0; i < maxn; i++) {
        if (qian[i]) {
            if (cnt)  printf(" ");
            printf("%d", qian[i]);
            cnt++;
        }
    }
}
int main() {
    int t = 1;
    while(t--)
        solve();
    return 0;
}