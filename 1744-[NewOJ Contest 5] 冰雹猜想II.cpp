#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> st;
ll n;
void dfs(ll x,ll cnt)
{
//	cout<<x<<" "<<cnt<<endl;
	if(cnt==0)
	{
		st.insert(x);
		return;
	}
	if(x&1)
	{
		dfs(x*2,cnt-1);
	}
	else
	{
		dfs(x*2,cnt-1);
		if((x-1)%3==0&&((x-1)/3)&1&&(x-1)/3!=1)
		dfs((x-1)/3,cnt-1);
	}
}
int main ()
{
	cin>>n;
	dfs((ll)1,n);
	cout<<st.size()<<endl;
	return 0;
}