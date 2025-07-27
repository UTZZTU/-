#include <bits/stdc++.h>
using namespace std;
set<int> p;
int n,k,q,h;
vector<pair<int,int>> vec;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		p.insert(k);
	}
	for(auto it=p.begin();it!=p.end();it++)
	{
		q=*it;
		q+=15;
		while(it!=p.end()&&*it<q)
		it++;
		if(it==p.end())
		{
			vec.push_back({q,q+29});
			break;
		}
		else
		{
			if(*it<=q+29)
			{
				h=q+29+15;
				vec.push_back({q,h});
				while(it!=p.end()&&*it<h+1)
				it++;
				if(it==p.end())
				break;
				else
				it--;
			}
			else
			{
				h=q+29;
				vec.push_back({q,h});
				while(it!=p.end()&&*it<h+1)
				it++;
				if(it==p.end())
				break;
				else
				it--;
			}
		}
	}
	for(auto it=vec.begin();it!=vec.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}