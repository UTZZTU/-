#include <bits/stdc++.h>
using namespace std;
int n,m,f[110];
map<string,int> mp;
vector<int> vec;
string s;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		mp[s]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		vec.push_back(it->second);
	}
	sort(vec.begin(),vec.end());
	int res1=0,res2=0;
	int pos=1;
	for(int i=vec.size()-1;i>=0;i--)
	{
		res1+=vec[i]*f[pos++];
	}
	pos=n;
	for(int i=vec.size()-1;i>=0;i--)
	{
		res2+=vec[i]*f[pos--];
	}
	cout<<res1<<" "<<res2<<endl;
}
int main ()
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