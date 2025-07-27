#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
map<vector<int>,bool> mp;
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}
ll n,vis[50],c[55],sx[55],summ;
vector<ll> vec[55];
ll cl(int x)
{
	vis[x]=1;
	ll num=1;
//	if(vec[x].size()==0)
//	{
//		return 1ll;
//	}
	for(int i=0;i<vec[x].size();i++)
	{
		num+=cl(vec[x][i]);
	}
	return num;
}
void dfs(int lev,ll sum,ll cnt,vector<int> vec)
{
//	cout<<"dfs"<<lev<<" "<<sum<<" "<<cnt<<endl; 
	while(lev<=n&&vis[sx[lev]]) lev++;
	int sy=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) sy++;
	}
	if(!sy)
	{
		if(mp[vec]==false)
		{
//			cout<<"VEC:";
//			for(int i=0;i<vec.size();i++)
//			{
//				cout<<vec[i]<<" ";
//			}
//			cout<<endl;
			summ=(summ+sum)%mod;
//			cout<<sum<<endl;
			mp[vec]=true;
		}
		return;
	}
	ll p=cl(sx[lev]);
	vec.push_back(sx[lev]);
//	cout<<p<<endl;
	sum=(sum*qmi(c[cnt],p))%mod;
	dfs(lev+1,sum,cnt+1,vec);
}
int main ()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int fa;
		cin>>fa;
		vec[fa].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		sx[i]=i;
	}
	do{
		vector<int> vec;
		memset(vis,0,sizeof vis);
		dfs(1,1ll,1,vec);
//		cout<<summ<<endl;
	}while(next_permutation(sx+1,sx+1+n));
	cout<<summ%mod;
	return 0;
}
