// AC
#include <bits/stdc++.h>

using namespace std;
#define PII pair<int, int>
const int N = 1010;
vector<int> ans;
int f[N][N], op[N][N];
PII pre[N][N];
vector<int> s1, s2;
int n, m, x, y;

void init()
{
	// 边界值初始化
	for(int i = 0;i <= n;i ++) f[i][0] = i, op[i][0] = 0, pre[i][0] = {i-1, 0};
	for(int i = 0;i <= m;i ++) f[0][i] = i, op[0][i] = 3, pre[0][i] = {0, i-1};
}

int main()
{
	s1.push_back(0);
	cin >> x;
	while(x != -1)
	{
		s1.push_back(x);
		cin >> x;
	}
	
	s2.push_back(0);
	cin >> y;
	while(y != -1)
	{
		s2.push_back(y);
		cin >> y;
	}
	n = s1.size()-1;
	m = s2.size()-1;
	init();
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			// 是否需要修改
			int flag = 1;
			if(s1[i] == s2[j]) flag = 0;
			int del = f[i-1][j] + 1;
			int add = f[i][j-1] + 1;
			int upd = f[i-1][j-1] + flag;
			f[i][j] = min(del, min(add, upd));
			// 记录操作类型和位置  
			if(f[i][j] == del)
			{
				op[i][j] = 0;
				pre[i][j] = {i-1, j};
			}
			else if(f[i][j] == add)
			{
				op[i][j] = 3;
				pre[i][j] = {i, j-1};
			}
			else
			{
				// 更新 
				if(flag) op[i][j] = 1;
				else op[i][j] = 2;
				pre[i][j] = {i-1, j-1};
			}
		}
	}
	cout << f[n][m] << endl;
	ans.push_back(op[n][m]);
	PII t = pre[n][m];
	while(t.first || t.second)
	{
		int i = t.first, j = t.second;
		ans.push_back(op[i][j]);
		t = pre[i][j];
	}
	reverse(ans.begin(), ans.end());
	for(int x : ans) cout << x;
	return 0;
}
