#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+10;
int num[MAXN], len;
long long k;
int main()
{
	scanf("%d%lld", &len, &k);
	for (int i=0; i<len; i++) scanf("%d", num+i);
	sort(num, num+len);
	int L = 2*num[0], R = 2*num[len-1];
	while (L <= R)
	{
		int M = (L+R)>>1;
		long long cot = 0;
		for (int i=0; i<len; i++)
		{
			int l = 0, r = i-1;
			while (l <= r)
			{
				int m = (l + r) >> 1;
				if (num[m]+num[i] < M) l = m + 1;
				else r = m - 1;
			}
			cot += r + 1;
		}
		if (cot < k) L = M + 1;
		else R = M - 1;
	}
	printf("%d\n", R);
	return 0;
}
