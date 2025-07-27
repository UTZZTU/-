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
	for (int i = 1; i <= n; i++)scanf("%s", mark[i] + 1);//ȷ����һ����λ����(1,1)
}
void color(int x, int y, int size)
{
	//���x�Ǹ�����һ��x+size(i-1)�����yҲͬ�������Ϳ�����������
	//��Ҫ�ı���ɫ�����꾿��������
	int sx = x, sy = y, ex = x + size, ey = y + size;//STA(sx,sy),END(ex,ey)
	for (int i = sx; i < ex; i++)//ĩβ����<=�����һ�����ڵ�ǰ������
		for (int j = sy; j < ey; j++)
			save[i][j] = 1;//�ı�boolֵ�����ʱ����boolֵ�������
}
void change(int n, int x, int y, int size)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)//�жϸ�ͼ��ǰ����費��ҪͿɫ
			if (mark[i][j] == '*')//�����Ҫ
				color(x + size * (i - 1), y + size * (j - 1), size);//������Ϣ
}
int main()
{
	int n = read, k = read;//�����С���������
	INPUT(n);//����
	int lim = qpow(n, k, 1e8);//��ȷ��������Ҫ���ٵĿռ�����������飬����5^5=3125��
	for (int size = k; size >= 1; size--)
	{
		int x = qpow(n, size, 1e8);//�жϵ�ǰ���򶨵Ĳ�������
		for (int i = 1; i <= lim; i += x)//lim�Ǳ߽�
			for (int j = 1; j <= lim; j += x)//ÿ��i��j������x
				if (!save[i][j])//�������ǰ�ɫ��������ǰ׶��ǰף��Ǻڶ��Ǻ�
					change(n, i, j, x / n);//��Ϊ�ڿ���������Ĵ�СҪСһ��
	}
	OUT(lim);//���
}

