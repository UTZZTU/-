//#include<__msvc_all_public_headers.hpp>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n;
pair<int, int>a[N];
void init()
{
	
}
void solve()
{
	cin >> n;
	int m;
	cin >> m;
	init();
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = { x,y };
	}
	vector<pair<int,int>>num1,num2;
	ll ma = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].first != 1)
		{//��˵㲻��1��
			num1.push_back({ a[i].first,1 });//��˵���+1
			num1.push_back({ a[i].second + 1,-1 });//�Ҷ˵���-1
		}
		if (a[i].second != m)
		{//�Ҷ˵㲻��m��
			num2.push_back({ a[i].first,1 });
			num2.push_back({ a[i].second + 1,-1 });
		}
	}
	sort(num1.begin(), num1.end());//��С��������
	sort(num2.begin(), num2.end());
	int las = 0;//��ǰ���±�
	ll cnt = 0;//�������ǰ׺��
	for (int i = 0; i < num1.size(); i++)
	{//�������ж˵�
		if (num1[i].first > las)
		{//�±��ƶ���ά�����ֵ
			ma = max(ma, cnt);
		}
		cnt += num1[i].second;
		las = num1[i].first;
	}
	las = 0, cnt = 0;
	for (int i = 0; i < num2.size(); i++)
	{
		if (num2[i].first > las)
		{
			ma = max(ma, cnt);
		}
		cnt += num2[i].second;
		las = num2[i].first;
	}
	cout << ma;
	cout << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	//t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
