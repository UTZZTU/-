#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<ll> st;
ll t,n,k;
char c;
string u,v;
map<string,ll> mp1;
map<ll,string> mp2;
string lenth(ll n)
{
	string res;
	while(n)
	{
		k=n%10;
		if(k&1)
		res+='1';
		else
		res+='0';
		n/=10;
	}
	while(res.size()<18)
	res+='0';
	return res;
}
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>c;
		if(c=='+')
		{
			cin>>n;
			st.insert(n);
			v=lenth(n);
			mp1[v]++;
			mp2[n]=v;
		}
		else if(c=='-')
		{
			cin>>n;
			auto it=st.lower_bound(n);
			st.erase(it);
			v=mp2[n];
			mp1[v]--;
		}
		else if(c=='?')
		{
			cin>>u;
			reverse(u.begin(),u.end());
			while(u.size()<18)
			u+='0';
			cout<<mp1[u]<<endl;
		}
	}
	return 0;
}