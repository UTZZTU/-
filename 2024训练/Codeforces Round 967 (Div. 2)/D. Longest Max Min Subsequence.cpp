#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,a[300010],last[300010],vis[300010],cnt[300010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		last[i]=n+1;
		vis[i]=0;
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		last[a[i]]=i;
	}
	set<int> st;
	set<pair<int,int>> p1;
	set<pair<int,int>> p2;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>0)
		{
			mx++;
			st.insert(last[i]);
		}
	}
	vector<int> vec;
	int cur=0,l=1;
	while(vec.size()<mx)
	{
		int x=*st.begin();
		while(cur<x)
		{
			++cur;
			if(!vis[a[cur]])
			{
				p1.insert({a[cur],cur});
				p2.insert({a[cur],-cur});
			}
		}
		int tmp;
		if(vec.size()&1)  //small
		{
			while((*p1.begin()).second<l||vis[(*p1.begin()).first])
			{
				auto p=(*p1.begin());
				p2.erase(make_pair(p.first,-p.second));
				p1.erase(p);
			}
			auto p=(*p1.begin());
			tmp=p.first;
			l=p.second;
			p2.erase(make_pair(p.first,-p.second));
			p1.erase(p);
		}
		else  //big
		{
			while(abs((*p2.rbegin()).second)<l||vis[(*p2.rbegin()).first])
			{
				auto p=(*p2.rbegin());
				p1.erase(make_pair(p.first,-p.second));
				p2.erase(p);
			}
			auto p=(*p2.rbegin());
			tmp=p.first;
			l=abs(p.second);
			p1.erase(make_pair(p.first,-p.second));
			p2.erase(p);
		}
		vec.push_back(tmp);
		vis[tmp]=1;
		st.erase(last[tmp]);
	}
	cout<<mx<<endl;
	for(auto c:vec)
	{
		cout<<c<<" ";
	}
	cout<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}