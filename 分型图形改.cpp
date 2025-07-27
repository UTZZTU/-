#include<algorithm>
#include<iostream>
#include<string.h>
#include<utility>
#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#pragma warning(disable:4244)
#define PI 3.1415926536
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll ll_inf = 9223372036854775807;
const int int_inf = 2147483647;
const short short_inf = 32767;
const char char_inf = 127;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll read() {
	ll c = getchar(), Nig = 1, x = 0;
	while (!isdigit(c) && c != '-')c = getchar();
	if (c == '-')Nig = -1, c = getchar();
	while (isdigit(c))x = ((x << 1) + (x << 3)) + (c ^ '0'), c = getchar();
	return Nig * x;
}
inline void out(ll a)
{
	if (a < 0)putchar('-'), a = -a;
	if (a >= 10)out(a / 10);
	putchar(a % 10 + '0');
}
ll qpow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1)res = (res * x) % mod;
		x = (x * x) % mod; n >>= 1;
	}
	return res;
}
#define Floyd for(int k = 1; k <= n; k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
#define read read()
char mark[200][200];
bool save[4000][4000];
void OUT(int lim)
{
	for (int i = 1; i <= lim; i++) {
		for (int j = 1; j <= lim; j++)
		{
			if (save[i][j])putchar('*');
			else putchar('.');
		}
		putchar('\n');
	}
}
void INPUT(int n)
{
	for (int i = 1; i <= n; i++)scanf("%s", mark[i] + 1);//确保第一个的位置是(1,1)
}
void color(int x, int y, int size)
{
	//这个x是根据上一步x+size(i-1)算出，y也同理。这样就可以求出来这个
	//需要改变颜色的坐标究竟在哪了
	int sx = x, sy = y, ex = x + size, ey = y + size;//STA(sx,sy),END(ex,ey)
	for (int i = sx; i < ex; i++)//末尾不可<=，最后一个不在当前区块内
		for (int j = sy; j < ey; j++)
			save[i][j] = 1;//改变bool值，输出时根据bool值输出即可
}
void change(int n, int x, int y, int size)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)//判断该图像当前这块需不需要涂色
			if (mark[i][j] == '*')//如果需要
				color(x + size * (i - 1), y + size * (j - 1), size);//传入信息
}
int main()
{
	int n = read, k = read;//输入大小，输入次数
	INPUT(n);//输入
	int lim = qpow(n, k, 1e8);//来确定最终需要多少的空间来存这个数组，至少5^5=3125个
	for (int size = k; size >= 1; size--)
	{
		int x = qpow(n, size, 1e8);//判断当前所框定的操作区域
		for (int i = 1; i <= lim; i += x)//lim是边界
			for (int j = 1; j <= lim; j += x)//每次i，j都增加x
				if (!save[i][j])//该区域是白色区域，如果是白都是白，是黑都是黑
					change(n, i, j, x / n);//因为在框定区域操作的大小要小一级
	}
	OUT(lim);//输出
}

