#include <bits/stdc++.h>
using namespace std;
int n,q,x,y,l,r;
string s;
map<pair<int,int>,set<int> >mp;
vector<pair<int,int> >vec;
bool check(pair<int,int> p,int l,int r)
{
	if(!mp.count(p)) return false;
	auto mid=mp[p].lower_bound(l);
	return mid!=mp[p].end()&&*mid<=r;
}
void solve()
{
	
	cin>>n>>q>>s;
	pair<int,int> p={0,0};
	mp[p].emplace(0);
	vec.push_back(p);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U') p.second++;
		else if(s[i]=='D') p.second--;
		else if(s[i]=='L') p.first--;
		else p.first++;
		mp[p].emplace(i+1);
		vec.push_back(p);
	}
	while(q--)
	{
		cin>>x>>y>>l>>r;
		if(check({x,y},0,l-1)||check({vec[l-1].first+vec[r].first-x,vec[l-1].second+vec[r].second-y},l,r-1)||check({x,y},r,n))
		puts("YES");
		else puts("NO");
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}