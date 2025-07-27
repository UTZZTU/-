#include <bits/stdc++.h>
using namespace std;
map<char,pair<int,int>> mp;
int t;
string u;
int main ()
{
	mp['q']={1,1};
	mp['w']={1,2};
	mp['e']={1,3};
	mp['r']={1,4};
	mp['t']={1,5};
	mp['y']={1,6};
	mp['u']={1,7};
	mp['i']={1,8};
	mp['o']={1,9};
	mp['p']={1,10};
	mp['a']={2,1};
	mp['s']={2,2};
	mp['d']={2,3};
	mp['f']={2,4};
	mp['g']={2,5};
	mp['h']={2,6};
	mp['j']={2,7};
	mp['k']={2,8};
	mp['l']={2,9};
	mp['z']={3,2};
	mp['x']={3,3};
	mp['c']={3,4};
	mp['v']={3,5};
	mp['b']={3,6};
	mp['n']={3,7};
	mp['m']={3,8};
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u;
		for(int i=0;i<u.size();i++)
		{
			if(u[i]>='a')
			cout<<mp[u[i]].first<<" "<<mp[u[i]].second<<endl;
			else
			cout<<3<<" "<<1<<" "<<mp[u[i]+32].first<<" "<<mp[u[i]+32].second<<endl;
		}
	}
	return 0;
}