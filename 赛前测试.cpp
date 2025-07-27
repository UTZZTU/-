#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<vector<ll>,ll> mp;
pair<vector<ll>, ll> p[10010];
bool cmp(pair<vector<ll>, ll> x,pair<vector<ll>, ll> y)
{
	if(x.second!=y.second)
	return x.second>y.second;
	else
	{
		for(ll i=0;i<x.first.size();i++)
		{
			if(x.first[i] != y.first[i])
                return x.first[i] < y.first[i];
		}
	}
}
int main ()
{
	int n,m,k;
	cin>>n>>m;
	vector<ll> w;
	for(int i=1;i<=n;i++)
	{
		w.clear();
		for(int j=1;j<=m;j++)
		{
			cin>>k;
			w.push_back(k);
		}
		mp[w]++;
	}
	ll o=1;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		p[o].first=it->first;
		p[o].second=it->second;
		o++;
	}
	o--;
	sort(p+1,p+1+o,cmp);
	cout<<mp.size()<<endl;
	for(ll i = 1;i <= o;i++){
        cout << p[i].second;
        for(ll j = 0;j < p[i].first.size();j++){
            cout << " " << p[i].first[j];
        }
        if(i != o)
        cout << endl;
    }
    return 0;
}