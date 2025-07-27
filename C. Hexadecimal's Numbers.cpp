#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res;
bool judge(vector<int> vec)
{
	int num=0;
	for(int i=0;i<vec.size();i++)
	{
		num=num*10+vec[i];
		if(num>n) return false;
	}
	return true;
}
void dfs(int level,vector<int> vec)
{
	if(!judge(vec))
	{
		return;
	}
	res++;
	vec.push_back(1);
	dfs(level+1,vec);
	vec.pop_back();
	vec.push_back(0);
	dfs(level+1,vec);
}
void solve()
{
	cin>>n;
	vector<int> vec;
	vec.push_back(1);
	dfs(1,vec);
	cout<<res<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}