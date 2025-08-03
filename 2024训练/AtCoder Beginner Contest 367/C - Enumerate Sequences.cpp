#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,f[10];
void dfs(int x,vector<int> vec,int sum)
{
	if(x>n)
	{
		if(sum%k==0)
		{
			for(auto c:vec)
			{
				cout<<c<<" ";
			}
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=f[x];i++)
	{
		vec.push_back(i);
		dfs(x+1,vec,sum+i);
		vec.pop_back();
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>f[i];
	vector<int> vec;
	dfs(1,vec,0);
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