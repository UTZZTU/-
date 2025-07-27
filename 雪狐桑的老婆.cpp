#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,x,y;
map<ll,ll> mp1;
map<ll,char> mp2;
char xb1,xb2;
string a="add",b="query",c="querysum",u;
ll find(ll x)
{
	while(mp1[x]!=x) x=mp1[x]=mp1[mp1[x]];
	return x;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	mp1[1]=1;
	getchar();
	while(n--)
	{
		cin>>u;
		if(u==a)
		{
			cin>>x>>y>>xb1>>xb2;
			mp2[x]=xb1;
			mp2[y]=xb2;
			if(!mp1.count(x)&&!mp1.count(y))
			{
				mp1[x]=y;
				mp1[y]=y;
			}
			else if(!mp1.count(x))
			{
				mp1[x]=y;
			}
			else if(!mp1.count(y))
			{
				mp1[y]=x;
			}
			else
			{
				ll eu=find(x),ev=find(y);
				if(eu!=ev)
				mp1[ev]=eu;
			}
		}
		else if(u==b)
		{
			cin>>x;
			if(!mp1.count(x))
			cout<<"NO"<<endl;
			else if(mp2[x]=='M')
			cout<<"NO"<<endl;
			else
			{
				ll eu=find(1),ev=find(x);
				if(eu==ev)
				cout<<"YES"<<endl;
				else
				cout<<"NO"<<endl;
			}
		}
		else if(u==c)
		{
			ans=0;
			ll eu=find(1),ev;
			for(auto it=mp1.begin();it!=mp1.end();it++)
			{
				if(it->first==1||mp2[it->first]=='M')
				continue;
				ev=find(it->first);
				if(eu==ev)
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}