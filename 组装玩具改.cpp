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
 
int n;
LL ans, m;
int x[100005], y[100005];
struct node
{
	int id, num, tim;//num为剩的，tim为还剩下的次数
	bool operator <(const node &x)const{
		return tim > x.tim;//将剩下可以组装玩具次数少的放在前面
	}
};
 
priority_queue<node> q;
 
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
 
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &x[i]);
	}
	LL sum = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &y[i]);
		sum += y[i];
	}
	int minn = 1e9 + 5;//找出不用万能材料够组成多少个玩具
	for (int i = 1; i <= n; i++){
		minn = min(minn, x[i] / y[i]);
	}
	ans += minn;//记录次数
	LL need = 0;//已经用完的材料，如果要在组装玩具，那么接下来需要y[i]个
	for (int i = 1; i <= n; i++){
		x[i] -= minn * y[i];//更新每种材料还剩下的个数
		if(!x[i]){
			need += y[i];
		}else q.push(node{i, x[i], x[i] / y[i]});
	}
	int tim = 0;//标记前一次组装了几个玩具
	while(q.size()){
		node t = q.top();
		q.pop();
		int w = y[t.id] - t.num % y[t.id];//假设可以装t.num + 1次，那么t这个材料还要几个
		m -= w + need * (t.tim - tim + 1);
		if(m < 0){//如果不能装t.num+1个玩具，那么看最多可以装多少个玩具
			int tt = m + w + need * (t.tim - tim + 1);
			if(need) ans += tt / need;//防止need=0运行错误
			break;
		}
		ans += t.tim - tim + 1;//更新可以装玩具的次数
		tim = t.tim + 1;//更新上次可以装玩具的次数
		need += y[t.id];//第t.id中材料用完了,那么。。。
		while(q.size()){
			node v = q.top();
			if(v.tim == t.tim){//看可以组装次数相同的，想法同上
				m -= y[v.id] - v.num % y[v.id];
				if(m < 0){
					ans--;
					break;
				}
				need += y[v.id];
				q.pop();
			}else break;
		}
		if(m < 0) break;
	}
 
	if(m >= sum) ans += m / sum;//如果还有剩余，那么更新ans
	printf("%lld\n", ans);
 
	return 0;
}
