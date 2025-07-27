#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<set>
#define debug(x) cout << "[" << #x <<": " << (x) <<"]"<< endl
#define CLE(a,b) memset(a,b,sizeof(a))
#define MEC(a,b) memcpy(a,b,sizeof(a))
#define ll long long
#define inff 0x7fffffff
using namespace std;
int a[10005], b[10005], c[10005];
int n;
double F(double x)//寻找该点所对应所有函数值的最大值
{
	double ans;
	for (int i = 0;i < n;i++)
	{
		if (i == 0)
			ans = 1.0 * a[i] * x * x + 1.0 * b[i] * x + 1.0 * c[i];
		else
			ans = max(ans, 1.0 * a[i] * x * x + 1.0 * b[i] * x + 1.0 * c[i]);

	}
	return ans;
}
int main()
{
	int test;
	cin >> test;
	while (test--)
	{	
		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> a[i] >> b[i] >> c[i];
		double l = 0.0, r = 1000.0;
		double lm, rm;
		while (fabs(r - l) > 1e-10)//精度尽可能开大点防WA
		{
			lm = l + (r - l) / 3;
			rm = r - (r - l) / 3;
			if (F(lm) > F(rm))
				l = lm;
			else
				r = rm;
		}
		printf("%.4f\n", F(lm));
	}
	return 0;
}

