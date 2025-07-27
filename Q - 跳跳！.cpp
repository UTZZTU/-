#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	ll ans = 0;
	sort(a, a + n + 1);
	int l = 0, r = n;
	while(l != r) {
		ans += pow(a[r] - a[l], 2);
		l++;
		if(l != r) {
			ans += pow(a[r] - a[l], 2);
			r--;
		}
	}
	cout << ans << endl;
	return 0;
}
