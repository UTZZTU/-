#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Node {
	int dis;
	int d;
	friend bool operator<(Node n1, Node n2)
	{
		if (n1.dis == n2.dis)
			return n2.d < n1.d;//距离相等就把小的先弹出
		else
			return n2.dis < n1.dis;//否则就先弹出距离小的
	}
};
int main()
{
	int t;
	int n;
	int cnt;
	Node cur, next;
	int ans;
	scanf("%d", &t);
	while (t--)
	{
		priority_queue<Node> q;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d%d", &cur.dis, &cur.d);
			q.push(cur);
		}
		cnt	 = 0;
		ans = 0;
		while (!q.empty())
		{
			cnt++;
			cur = q.top();
			q.pop();
 
			ans = max(ans, cur.dis);
			if (cnt % 2)
			{
				next.dis = cur.dis + cur.d;
				next.d = cur.d;
				q.push(next);
			}
		}
 
		printf("%d\n", ans);
	}
	return 0;
}