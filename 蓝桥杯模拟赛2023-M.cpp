#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,c=1;
int cnt;
signed main ()
{
	scanf("%lld",&l);
	while(c<l)
	{
		c*=(long long)2;
		cnt++;
	}
	printf("%lld",cnt);
	return 0;
}
//蓝桥杯模拟赛2023-A