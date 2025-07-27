#include <bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010];
bool judge()
{
	if(n<=2) return true;
	int l=1,r=n;
	l++,r--;
	while(l<=r)
	{
		if(b[l]+b[r]!=b[1]+b[n]) return false;
		l++,r--;
	}
	return true;
}
void solve()
{
	cin>>n;
	map<int,multiset<int>> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		mp[a[i]].insert(i);
	}
	sort(b+1,b+1+n);
	if(judge())
	{
		cout<<"YES"<<endl;
		if(n<=2)
		{
			cout<<0<<endl;
		}
		else
		{
			vector<pair<int,int>> vec;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==b[i]) continue;
				auto it=mp[b[i]].lower_bound(i+1);
				int pos=*it;
				mp[b[i]].erase(it);
				mp[b[i]].insert(i);
				auto itt=mp[a[i]].lower_bound(i);
				mp[a[i]].erase(itt);
				mp[a[i]].insert(pos);
				swap(a[i],a[pos]);
				vec.push_back({i,pos});
			}
			cout<<vec.size()<<endl;
			for(int i=0;i<vec.size();i++)
			{
				cout<<vec[i].first<<" "<<vec[i].second<<endl;
			}
		}
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}