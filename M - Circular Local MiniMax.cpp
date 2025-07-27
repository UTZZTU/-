#include <bits/stdc++.h> 
using namespace std;
const int maxn = 200010;

int n, m, k, u, v;
int a[maxn], b[maxn];
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	if (n & 1) {
		printf("No\n");
		return;
	}
	sort(a, a + n);
	int j = 0;
	for (int i = 0; i < n; i += 2) {
		b[i] = a[j++];
	}
	for (int i = 1; i < n; i += 2) {
		b[i] = a[j++];
	}
	bool flag = (b[0] < b[1] && b[0] < b[n-1]);
	flag &= (b[n-1] > b[n-2]);
	for (int i = 1; i < n - 1; ++i) {
		if (!(b[i] > b[i-1] && b[i] > b[i+1]) &&
			!(b[i] < b[i-1] && b[i] < b[i+1])) {
			flag = false;
			break;	
		}
	}
	if (!flag) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");
}
int main() {
	int t;
	scanf("%d", &t);
//	t = 1;
	while (t--) {
		solve();
	}
}
/*

*/
