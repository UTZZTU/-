#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;
const int N = 1010;
typedef long long LL;

int n, m;
int a[N];

int cal(vector<int> s)
{
	int dp[N] = {0};
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++){
			if(s[i] > s[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	
	int ml = 1;
	for (int i = 0; i < n; i++) {
		ml = max(ml, dp[i] + 1);
	}

	return ml;
}

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int mlen = 1;
	LL ans = 0;
	for (LL i = 0; i < (1 << n); i++) {
		deque<int> q;
		for (int j = 0; j < n; j++) {
			if((i >> (n - j)) & 1)
				q.push_back(a[j]);
			else
				q.push_front(a[j]);
		}
		
		vector<int> s;
		for(int &x : q)
			s.push_back(x);
		
		
		int ml = cal(s);
		if(ml > mlen)
			{
				mlen = ml;
				ans = i;
			}
		
		if(mlen == n)
			{
				break;
			}
	}
	
	cout << mlen << endl;
	for (int i = 0; i < n; i++) {
		cout << ((ans >> (n - i)) & 1 ? 'R' : 'L');
	}
	return 0;
}
