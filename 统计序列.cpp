/**/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>
 
typedef long long LL;
using namespace std;
 
int n, m;
LL a[100005];
 
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
 
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	LL t = 0, sum = 0;
	for (int i = 1; i <= m; i++){
		t += a[i], sum += a[i] * a[i];
	}
	LL ans = sum * m - t * t;
	for (int i = m + 1; i <= n; i++){
		t = t - a[i - m] + a[i];
		sum = sum - a[i - m] * a[i - m] + a[i] * a[i];
		ans = min(ans, sum * m - t * t);
	}
	printf("%lld\n", ans);
 
	return 0;
}
/**/
