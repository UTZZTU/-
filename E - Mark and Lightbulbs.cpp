#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#define int long long
using namespace std;
 
char a[200005], b[200005];
struct node{
	int l, r;
	node(int _l, int _r):l(_l), r(_r){}
};
signed main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		scanf("%lld%s%s", &n, a+1, b+1);
		if(a[1] != b[1] || a[n] != b[n]){
			puts("-1");
			continue;
		}
		vector<node> seg1, seg2;
		int start = -1;
		for(int i = 1; i <= n; i++){
			if(a[i] == '1' && start == -1) start = i;
			else if(a[i] == '0' && start != -1){
				seg1.push_back(node(start, i-1));
				start = -1;
			}
		}
		if(start != -1) seg1.push_back(node(start, n));
		start = -1;
		for(int i = 1; i <= n; i++){
			if(b[i] == '1' && start == -1) start = i;
			else if(b[i] == '0' && start != -1){
				seg2.push_back(node(start, i-1));
				start = -1;
			}
		}
		if(start != -1) seg2.push_back(node(start, n));
		if(seg1.size() != seg2.size()){
			puts("-1");
			continue;
		}
		int ans = 0;
		for(int i = 0; i < seg1.size(); i++)
			ans += abs(seg1[i].l-seg2[i].l)+abs(seg1[i].r-seg2[i].r);
		printf("%lld\n", ans);
	} 
    return 0;
}