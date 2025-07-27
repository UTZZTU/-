#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
void solve()
{
	cin>>n;
	map<map<int,int>,vector<int>>mp;
	for(int i=(int)pow(10,n-1);i<(int)pow(10,n);i++)
	{
		int x=sqrt(i);
		if(x*x==i)
		{
			map<int,int> mm;
			int j=i;
			while(j)
			{
				mm[j%10]++;
				j/=10;
			}
			mp[mm].push_back(i);
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if((it->second).size()>=n)
		{
			vector<int> vec=it->second;
			for(int i=0;i<vec.size();i++)
			{
				cout<<vec[i]<<endl;
			}
		}
	}
}
signed main ()
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
}
/*
10609
16900
19600
61009
90601
96100

1006009
1060900
1690000
1960000
6100900
9006001
9060100
9610000
*/