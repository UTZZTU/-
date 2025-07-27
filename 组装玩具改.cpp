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
	int id, num, tim;//numΪʣ�ģ�timΪ��ʣ�µĴ���
	bool operator <(const node &x)const{
		return tim > x.tim;//��ʣ�¿�����װ��ߴ����ٵķ���ǰ��
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
	int minn = 1e9 + 5;//�ҳ��������ܲ��Ϲ���ɶ��ٸ����
	for (int i = 1; i <= n; i++){
		minn = min(minn, x[i] / y[i]);
	}
	ans += minn;//��¼����
	LL need = 0;//�Ѿ�����Ĳ��ϣ����Ҫ����װ��ߣ���ô��������Ҫy[i]��
	for (int i = 1; i <= n; i++){
		x[i] -= minn * y[i];//����ÿ�ֲ��ϻ�ʣ�µĸ���
		if(!x[i]){
			need += y[i];
		}else q.push(node{i, x[i], x[i] / y[i]});
	}
	int tim = 0;//���ǰһ����װ�˼������
	while(q.size()){
		node t = q.top();
		q.pop();
		int w = y[t.id] - t.num % y[t.id];//�������װt.num + 1�Σ���ôt������ϻ�Ҫ����
		m -= w + need * (t.tim - tim + 1);
		if(m < 0){//�������װt.num+1����ߣ���ô��������װ���ٸ����
			int tt = m + w + need * (t.tim - tim + 1);
			if(need) ans += tt / need;//��ֹneed=0���д���
			break;
		}
		ans += t.tim - tim + 1;//���¿���װ��ߵĴ���
		tim = t.tim + 1;//�����ϴο���װ��ߵĴ���
		need += y[t.id];//��t.id�в���������,��ô������
		while(q.size()){
			node v = q.top();
			if(v.tim == t.tim){//��������װ������ͬ�ģ��뷨ͬ��
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
 
	if(m >= sum) ans += m / sum;//�������ʣ�࣬��ô����ans
	printf("%lld\n", ans);
 
	return 0;
}
