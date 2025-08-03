#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[10],s[1010],cnt,sum;
bool flag;
void dfs(int x,vector<int> vec,ll res)
{
	if(flag||x>cnt) return;
	if(res==sum-res&&vec.size()*2==cnt)
	{
		for(auto c:vec)
		{
			cout<<c<<endl;
		}
		flag=true;
		return;
	}
	vec.push_back(s[x]);
	dfs(x+1,vec,res+s[x]*s[x]);
	vec.pop_back();
	dfs(x+1,vec,res);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	do{
		ll num=0;
		for(int i=1;i<=n;i++)
		{
			num=num*10ll+f[i];
		}
		s[++cnt]=num;
		sum+=num*num;
	}while(next_permutation(f+1,f+1+n));
	vector<int> vec;
	dfs(1,vec,0ll);
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
