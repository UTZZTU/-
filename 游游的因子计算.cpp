#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI pair<int,int> 
#define fi first
#define se second
#define pb push_back
#define fr front
#define bk back
#define gl getline
set<ll> st;
map<ll,ll> mp;
ll a,b;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	st.insert((ll)1);
	for(ll i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			while(a%i==0)
			{
				a/=i;
				mp[i]++;
			}
		}
	}
	if(a>1) mp[a]++;
	for(ll i=2;i*i<=b;i++)
	{
		if(b%i==0)
		{
			while(b%i==0)
			{
				b/=i;
				mp[i]++;
			}
		}
	}
	if(b>1) mp[b]++;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		ll x=it->fi,y=it->se;
		while(y--)
		{
			vector<ll> vec;
			for(auto tt=st.begin();tt!=st.end();tt++)
			{
				vec.push_back((*tt)*x);
			}
			for(int i=0;i<vec.size();i++)
			{
				st.insert(vec[i]);
			}
		}
	}
	cout<<st.size()<<endl;
	for(auto it=st.begin();it!=st.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
}