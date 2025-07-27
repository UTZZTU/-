#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int f[N][3],a[N],s[N],ans;
int mx = -1;
int main () {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		mx = max(mx,a[i]);//题目没给m，自己找出mx
	}
	for(int i = 1; i <= n; ++i)
		s[a[i]] = 1;
	for(int i = 1; i <= mx; ++i)
		s[i] += s[i - 1];//记录前缀和

	for(int i = 1; i <= mx; ++i) {
		//更新第一个小组
		for(int k = 0; k <= 10 && i - k >= 0; ++k) //k是第一组的人数
			f[i][1] = max(f[i - 1][1],s[i] - s[i - k]);

		f[i][2] = f[i - 1][2];
		for(int j = 0; j <= 10 && i - j >= 2; ++j)
			f[i][2] = max(f[i][2] , f[i-j-2][1]+s[i]-s[i-j]);

	}
	for(int i = 0; i <= mx; ++i)
		ans = max(ans,f[i][2]);
	cout << ans << endl;
	return 0;
}