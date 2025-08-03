#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,f[5],a[5],sum,flag;
vector<ll> vec;
void dfs(int lev,vector<ll> v)
{
	if(flag) return;
	if(lev==vec.size()&&v.size()==vec.size()/2)
	{
		ll ssum=0;
		for(auto c:v)
		{
			ssum+=c*c;
		}
		if(ssum*2==sum)
		{
			flag=1;
			for(int i=0;i<v.size();i++)
			{
				if(i!=0) cout<<endl;
				cout<<v[i];
			}
		}
		return;
	}
	if(lev>=vec.size()) return;
	v.push_back(vec[lev]);
	dfs(lev+1,v);
	v.pop_back();
	dfs(lev+1,v);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=i;
	}
	do{
		ll num=0;
		for(int i=1;i<=n;i++)
		{
			num=num*10+a[f[i]];
		}
		vec.push_back(num);
		sum+=num*num;
//		cout<<num<<endl;
	}while(next_permutation(f+1,f+1+n));
	
	vector<ll> v; 
	dfs(0,v);
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