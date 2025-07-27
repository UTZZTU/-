#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp1,mp2;
string name[1010];
int score[1010];
void solve()
{
	string p;
	int maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>name[i]>>score[i];
		mp1[name[i]]+=score[i];
	}
	for(auto it=mp1.begin();it!=mp1.end();it++)
	{
		maxx=max(maxx,it->second);
	}
	for(int i=1;i<=n;i++)
	{
		mp2[name[i]]+=score[i];
		if(mp1[name[i]]==maxx&&mp2[name[i]]>=maxx)
		{
			p=name[i];
			break;
		}
	}
	cout<<p<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}