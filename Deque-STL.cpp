#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;
int a[10010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		deque<int> p;
		vector<int> o;
		int n,k,mx=0,i,y;
		cin>>n>>k;
		for(i=1;i<=k;i++)
		{
			cin>>y;
			mx=max(mx,y);
			p.push_back(y);
		}
		o.push_back(mx);
		for(i;i<=n;i++)
		{
			cin>>y;
			int w=p.front();
			p.pop_front();
			p.push_back(y);
			if(w==mx)
			{
				if(mx<=y)
				mx=y;
				else
				{
					int u=0;
					for(auto it=p.begin();it!=p.end();it++)
					{
						a[u++]=*it;
					}
					sort(a,a+p.size());
					mx=a[p.size()-1];
				}
			}
			else
			mx=max(mx,y);
			o.push_back(mx);
		}
		for(auto it=o.begin();it!=o.end();it++)
		{
			if(it!=o.begin())
			cout<<" ";
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}