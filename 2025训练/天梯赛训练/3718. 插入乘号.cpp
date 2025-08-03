#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,k,maxx;
string s;
//1 2 3 4 5
 //x x x x
void cl(vector<int> v)
{
	ll sum=1;
	int lst=0;
	for(int i=0;i<n-1;i++)
	{
		if(v[i]==1)
		{
			sum*=(ll)(stoi(s.substr(lst,i-lst+1)));
			lst=i+1;
		}
	}
	sum*=(ll)(stoi(s.substr(lst,n-lst)));
	if(sum>maxx) maxx=sum;
}
void dfs(vector<int> v,int cnt)
{
	if(cnt==n-1)
	{
		int sum=0;
		for(int i=0;i<n-1;i++)
		{
			if(v[i]==1) sum++;
		}
		if(sum==k)
		cl(v);
		return;
	}
	v.push_back(0);
	dfs(v,cnt+1);
	v.pop_back();
	v.push_back(1);
	dfs(v,cnt+1);
}
void solve()
{
	cin>>n>>k;
	cin>>s;
	vector<int> v;
	dfs(v,0);
	cout<<maxx;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}