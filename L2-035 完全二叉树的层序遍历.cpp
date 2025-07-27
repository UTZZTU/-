#include <bits/stdc++.h>
using namespace std;
int n, cnt, In[32], dfs[32];
void Func(int index) {
	if (index > n) return;
    dfs[index] = In[cnt++];
	Func(index << 1);
	Func(index << 1 | 1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> In[i];
	Func(1);
	cout << dfs[1];
	for (int i = 2; i <= n; i++) cout << ' ' << dfs[i];
	return 0;
}
