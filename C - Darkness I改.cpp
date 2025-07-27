#include<iostream>
using namespace std;
#define int long long 
int N, M;
signed main()
{
	cin >> N >> M;
	if (N == 1 || M == 1)return cout << max(N, M) / 2 + 1, 0;
	else if (N == M) return cout << N, 0;
	else
		(N & 1) || (M & 1) ? cout << (N / 2 + M / 2) + 1  : cout << (N / 2 + M / 2);
	return 0;
}