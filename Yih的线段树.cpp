#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,x,ans=9,maxx=2,t;
map<ll,int> mp;
int main ()
{
	mp[1]++;
	mp[3]++;
	mp[5]++;
	mp[7]++;
	mp[9]++;
	for(ans;ans<=1e9;)
	{
		t=(ll)pow(2,maxx);
		while(t)
		{
			if(t==2)
			{
				ans+=2;
				mp[ans]++;
				ans+=2;
				mp[ans]++;
				t=0;
			}
			else
			{
				ans+=t;
				mp[ans]++;
				t/=2;
			}
		}
		maxx++;
	}
	cin>>q;
	while(q--)
	{
		cin>>x;
		if(mp.count(x))
		cout<<"Y"<<endl;
		else
		cout<<"N"<<endl;
	}
	return 0;
}