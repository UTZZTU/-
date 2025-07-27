#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
string s;
int l[N], r[N], f[N];

void dfs(int u)
{
	f[u] = 1e9;
	if(l[u] == 0 && r[u] == 0)f[u] = 0;
	if(l[u]){
		dfs(l[u]);
		if(s[u] == 'L') f[u] = min(f[u], f[l[u]]);
		else f[u] = min(f[u], f[l[u]] + 1);
	}
	if(r[u]){
		dfs(r[u]);
		if(s[u] == 'R') f[u] = min(f[u], f[r[u]]);
		else f[u] = min(f[u], f[r[u]] + 1);
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cin >> s;
		s = " " + s;
				
		for(int i = 1; i <= n; i++){
			cin >> l[i] >> r[i];
		}
		
		dfs(1);
		
		cout << f[1] << endl;
	}
	
	return 0;
}