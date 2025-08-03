#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200010],m;
vector<int> vec[26];
vector<int> v[26];
string s;
void solve()
{
	set<int> st;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st.insert(a[i]);
	}
	if(st.size()>26)
	{
		cin>>m;
		while(m--)
		{
			cin>>s;
			cout<<"NO"<<endl;
		}
	}
	else
	{
		for(int i=0;i<26;i++)
		{
			vec[i].clear();
		}
		map<int,int> mp;
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(mp[a[i]]==0)
			{
				mp[a[i]]=cnt;
				cnt++;
			}
			vec[mp[a[i]]-1].push_back(i);
		}
		cin>>m;
		while(m--)
		{
			cin>>s;
			if(s.size()!=n)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				for(int i=0;i<26;i++) v[i].clear();
				for(int i=0;i<n;i++)
				{
					v[s[i]-'a'].push_back(i+1);
				}
				int flag=1;
				for(int i=0;i<26;i++)
				{
					for(int j=1;j<vec[i].size();j++)
					{
						if(s[vec[i][j-1]-1]!=s[vec[i][j]-1]) flag=0;
					}
				}
				for(int i=0;i<26;i++)
				{
					for(int j=1;j<v[i].size();j++)
					{
						if(a[v[i][j-1]]!=a[v[i][j]]) flag=0;
					}
				}
				if(flag) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}
	}
	
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