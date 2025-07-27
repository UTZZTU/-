#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,t;
pair<int,int> calc(ll n,ll m){
	if(m==0) return {0,0};
	ll pos = 1ll << n - 1, cnt = 1ll << 2*n -2;
	auto p = calc(n -1, m % cnt);
	ll k = m / cnt;
	if (k==0) return {p.second, p.first};
	else if(k==1) return {p.first, p.second+pos};
	else if(k==2) return {p.first+pos, p.second+pos};
	return {2*pos-1-p.second,pos-1-p.first};
}
int main ()
{
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		auto ac = calc(n, a - 1);
		auto bc = calc(n, b - 1);
		double x = ac.first - bc.first, y = ac.second - bc.second;
		printf("%.0f\n",sqrt(x*x + y*y) * 10);
	}
	return 0;
}