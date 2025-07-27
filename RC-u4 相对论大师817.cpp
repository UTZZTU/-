#include<bits/stdc++.h>
using namespace std;
 
map<string,int> mp;
map<int, string> mp2;
 
const int N = 1e3 + 10;
int pre[N];
bool st[N];
int h[N], e[N], ne[N], idx;
 
void add(int u, int v) {
	e[idx] = v, ne[idx] = h[u], h[u] = idx ++;
}
 
vector<string> res;	//	记录答案
 
void bfs(string T1) {
	string T2 = T1;
	if(T2.back() == '0')	T2.back() = '1';
	else	T2.back() = '0';
 
	int start = mp[T1], end = mp[T2];
	memset(pre, -1, sizeof pre);
	memset(st, false, sizeof st);
	queue<int> q;
	q.push(start);
	st[start] = true;
	
	while(!q.empty()) {
		auto t = q.front();
		q.pop();
		for(int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if(st[j])	continue;
			st[j] = true;
			q.push(j);
			pre[j] = t;
		}
	}
	
	if(pre[end] == -1)	return;	//未跑到起点, 无解
	
	vector<string> ans;
	
	while(pre[end] != 0) {	//记录路径
		ans.push_back(mp2[end]);
		end = pre[end];
	}
	
	
	if(res.empty() || (int)res.size() > (int)ans.size())	//此路更优, 替换答案
		res = ans;
	
	
}
 
int main() {
	int n, cnt = 0;
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; ++ i) {
		string s1, s2, t1 ,t2;
		cin >> s1 >> t1 >> s2 >> t2;
		s1 += t1, s2 += t2;
		if(!mp.count(s1))	mp[s1] = ++ cnt, mp2[cnt] = s1;	//	哈希
		if(!mp.count(s2))	mp[s2] = ++ cnt, mp2[cnt] = s2;	// 双向哈希
		add(mp[s2], mp[s1]);
	}
	
	for(auto &[x, y] : mp) {	// 枚举终点
		bfs(x);
	}
	
	for(int i = 0; i < (int)res.size(); i ++) {	//输出答案
		string t1, t2;
		for(int j = 0; j < (int)res[i].size() - 1; ++ j)	t1 += res[i][j];
		t2 += res[i].back();
		cout << t1 << " " << t2 << ' ';
		if(i != 0 )	{
			if(i == (int)res.size() - 1) {
				cout << "= ";
				for(int j = 0; j < res[0].size() - 1; ++ j) {
					cout << res[0][j];
				}
				cout << " " << res[0].back() << " " << t1 << " " << t2 << '\n';
			} 
			else	cout << t1 << " " << t2 << ' ';
		}
	}
	
	
	
	return 0;
}