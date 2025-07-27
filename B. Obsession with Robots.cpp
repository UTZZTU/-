#include <bits/stdc++.h>
using namespace std;
string s;
map<pair<int,int>,int> mp;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
void solve()
{
	int x=0,y=0;
	int prex,prey;
	cin>>s;
	mp[{x,y}]++;
	for(int i=0;i<s.size();i++)
	{
		prex=x,prey=y;
		if(s[i]=='L') x--;
		else if(s[i]=='R') x++;
		else if(s[i]=='U') y++;
		else y--;
		if(mp[{x,y}]>=1)
		{
			cout<<"BUG"<<endl;
			return;
		}
		for(int j=0;j<4;j++)
		{
			int xx=dx[j]+x,yy=dy[j]+y;
			if(xx==prex&&yy==prey) continue;
			if(mp[{xx,yy}]>=1) 
			{
				cout<<"BUG"<<endl;
				return;
			}
		}
		mp[{x,y}]++;
	}
	cout<<"OK"<<endl;
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