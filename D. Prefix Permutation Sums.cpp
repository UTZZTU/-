#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200010],res,flag;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		flag=0;
		map<ll,bool> mp;
		vector<ll> vec;
		for(int i=1;i<n;i++) 
		{
			cin>>a[i];
			ll k=a[i]-a[i-1];
			if(k>n)
			{
				vec.push_back(k);
			}
			else
			{
				if(mp[k]) vec.push_back(k);
				else mp[k]=true;
			}
		}
		if(vec.size()>1)
		{
			;
		}
		else
		{
			vector<ll> v;
			for(ll i=1;i<=n;i++)
			{
				if(!mp[i]) v.push_back(i);
			}
			if(v.size()==1)
			{
				if(vec.size()==1&&vec[0]==v[0]||vec.size()==0) flag=1;
			}
			else if(v.size()==2)
			{
				if(vec.size()==1&&vec[0]==v[0]+v[1]) flag=1;
			}
		}
		if(!flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}