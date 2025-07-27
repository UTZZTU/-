#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int pos;
char solve()
{
	cin>>s>>pos;
	int n=s.size();
	vector<int> vec[26];
	for(int i=0;i<n;i++)
	{
		vec[s[i]-'a'].push_back(i+1);
	}
	int pp=n*(n+1)/2;
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(mid*(mid+1)/2>pp-pos) r=mid;
		else l=mid+1;
	}
	int cnt=n-l,ff=0;
	if(l!=n) pos-=(l+1+n)*(n-l)/2;
	int ttp=cnt;
//	cout<<cnt<<" "<<pos<<" "<<l<<endl;
	for(int i=1;i<=n-cnt;i++)
	{
		int j=0;
		for(j;j<26;j++)
		{
//			cout<<j<<endl;
			auto it=lower_bound(vec[j].begin(),vec[j].end(),ff+1);
			if(it!=vec[j].end()&&*it-(ff+1)<=ttp)
			{
				ttp-=*it-(ff+1);
				ff=*it;
				break;
			}
		}
		if(i==pos)
		{
			return (char)('a'+j);
		}
	}
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	string v;
	while(t--)
	{
		v+=solve();
	}
	cout<<v<<endl;
	return 0;
}