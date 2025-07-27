#include <bits/stdc++.h>
using namespace std;
map<char,pair<int,int>> mp;
int sum;
int main ()
{
	mp['a']={2,1};
	mp['b']={2,2};
	mp['c']={2,3};
	mp['d']={3,1};
	mp['e']={3,2};
	mp['f']={3,3};
	mp['g']={4,1};
	mp['h']={4,2};
	mp['i']={4,3};
	mp['j']={5,1};
	mp['k']={5,2};
	mp['l']={5,3};
	mp['m']={6,1};
	mp['n']={6,2};
	mp['o']={6,3};
	mp['p']={7,1};
	mp['q']={7,2};
	mp['r']={7,3};
	mp['s']={7,4};
	mp['t']={8,1};
	mp['u']={8,2};
	mp['v']={8,3};
	mp['w']={9,1};
	mp['x']={9,2};
	mp['y']={9,3};
	mp['z']={9,4};
	string u;
	while(cin>>u)
	{
		sum=0;
		int sc=-1;
		for(int i=0;i<u.size();i++)
		{
			if(sc==-1)
			{
				sum+=mp[u[i]].second;
				sc=mp[u[i]].first;
			}
			else
			{
				if(mp[u[i]].first!=sc)
				{
					sum+=mp[u[i]].second;
				    sc=mp[u[i]].first;
				}
				else
				{
					sum+=mp[u[i]].second+2;
				    sc=mp[u[i]].first;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}