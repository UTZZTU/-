#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

set<int> s[55];
int n, m;	// n记录几组，m记录每组第一个数，即元素个数

int main()
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>m;
		while (m--)		// 牛逼 多学学 m是零的时候就不执行 真牛逼
		{
			int num;
			cin>>num;
			s[i].insert(num);	 // 往set容器里插入元素
		}
	}

	int k;
	cin>>k;
	while (k--)
	{
		int a, b;	// 记录索要计算的行
		cin >> a >> b;
		set<int>::iterator it; // 建立迭代器，用于查找
		int cnta = s[a].size(), cntb = s[b].size(), cnt = 0;
		for (it = s[a].begin(); it != s[a].end(); it++)
		{
			if (s[b].find(*it) != s[b].end())
				cnt++;
		}
		printf("%.2lf%\n", cnt*1.0 / (cnta + cntb - cnt) * 100);
	}
	return 0;
}