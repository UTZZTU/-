#include <bits/stdc++.h>
using namespace std;
struct line
{
	int l,r,h;
};
bool cmp(line a,line b)
{
	return a.h>b.h;
};
vector<line> vec;
multiset<int> st;
vector<int> p;
int n,m,l,r,h,level;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>h;
		vec.push_back({l,r,h});
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=1,k;i<=n;i++)
    {
    	cin>>k;
    	st.insert(k);
	}
	level=vec[0].h;
	for(int i=0;i<vec.size();i++)
	{
		if(level==vec[i].h)
		{
			auto it=st.lower_bound(vec[i].l);
			if(it==st.end())
			continue;
			while(it!=st.end()&&*it<=vec[i].r)
			{
				it=next(it);
				st.erase(prev(it));
				p.push_back(vec[i].l);
				p.push_back(vec[i].r);
			}
		}
		else
		{
			level=vec[i].h;
			for(int j=0;j<p.size();j++)
			st.insert(p[j]);
			p.clear();
			auto it=st.lower_bound(vec[i].l);
			if(it==st.end())
			continue;
			while(it!=st.end()&&*it<=vec[i].r)
			{
				it=next(it);
				st.erase(prev(it));
				p.push_back(vec[i].l);
				p.push_back(vec[i].r);
			}
		}
	}
	for(int j=0;j<p.size();j++)
	st.insert(p[j]);
	cout<<st.size();
	return 0;
}