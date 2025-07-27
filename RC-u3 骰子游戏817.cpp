#include<bits/stdc++.h>
using namespace std;
int arr[6], b[6], n = 5;
 
struct info {
	int x, y, cnt;
};
 
info ans;	//答案, x为分子, y为分母, cnt为重置多少个筛子
int ct, p;	//ct 为每种情况的成功次数, p为初始序列的得分
vector<int> v;	//重置哪些位置上的筛子
 
int check(int a[]) {	//判断等级的函数
	map<int,int> mp;
	for(int i = 1; i <= n; ++ i) {
		mp[a[i]] ++;
	}
	if((int)mp.size() == 1)	return 1;
	
	if((int)mp.size() == 2) {
		for(auto &[x, y] : mp) {
			if(y == 4) {
				return 2;
			}
			if(y == 3) {
				return 3;
			}
		}
		
	}
	
	if((int)mp.size() == 5 && !mp.count(1))	return 4;
	if((int)mp.size() == 5 && !mp.count(6))	return 5;
	
	for(auto &[x, y] : mp) {
		if(y == 3) {
			return 6;
		}
	}
	
	int cnt = 0;
	for(auto &[x, y] : mp) {
		if(y == 2) {
			++ cnt;
		}
	}
	
	if(cnt == 2)	return 7;
	if(cnt == 1)	return 8;
	return 9;
	
}
 
void dfs(int now) {
	if(now == (int)v.size()) {
		if(check(b)< p)	++ ct;	//成功
		return;
	}
	
	for(int i = 1; i <= 6; ++ i) {	//枚举位置上的所有数字(情况)
		b[v[now]] = i;
		dfs(now + 1);
	}
	
}
 
void solve() {
	for(int i = 1; i <= n; ++ i) {
		cin >> arr[i];
	}
	ans = {0, 0, 0};	//多组测试数据, 记得清空答案
	p = check(arr);	// 得到初始序列的得分
	if(p == 1) {	//得分最高级, 直接输出
		cout << 0 << " " << 0 << " " << 1 << '\n';
		return;
	}
	int q = 1;	//概率的分母
	for(int k = 1; k <= 5; ++ k) {	// 重摇k个筛子
		q *= 6;	//每次多重置一个筛子, 分母 * 6
		ans.x *= 6, ans.y *= 6;	// 给答案通分
		
		for(int i = 0; i < 1 << n; ++ i) {	//状态压缩, 在二进制情况从右往左数第i位为1则表示重置第i位筛子
			if(__builtin_popcount(i) != k)	continue;	// 二进制数的1不为k, 即重置的筛子数量不等于k
			v.clear();	//清空上次的内容
			ct = 0;	//重置成功次数
			for(int j = 1; j <= 5; ++ j)	b[j] = arr[j];	//重置b数组
			
			for(int j = 0; j < 5; ++ j) {
				if(i >> j & 1) {	//拿到重置筛子的位置
					v.push_back(j + 1);
				}	
			}
			
			
			dfs(0);
			
			if(ans.y == 0)	ans = {ct, q, k};	//第一次直接记录答案
			else {
				if(ct > ans.x)	{	//比答案更优 记录
					ans = {ct, q, k};
				}		
			}
					
		}
	}
	
	int ttt = __gcd(ans.x, ans.y);//题目要求最简分数
 
	
	cout << ans.cnt << " " << ans.x / ttt << " " << ans.y / ttt << '\n';
	
	
}
 
int main() {
	
	int t;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}