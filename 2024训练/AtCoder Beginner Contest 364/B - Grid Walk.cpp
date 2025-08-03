#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sx,sy;
string s[100],t;
void solve()
{
	cin>>n>>m;
	cin>>sx>>sy;
	sx--,sy--;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	cin>>t;
	for(auto c:t)
	{
		if(c=='L')
		{
			if(sy-1>=0&&s[sx][sy-1]=='.') sy--;
		}
		else if(c=='R')
		{
			if(sy+1<m&&s[sx][sy+1]=='.') sy++;
		}
		else if(c=='U')
		{
			if(sx-1>=0&&s[sx-1][sy]=='.') sx--;
		}
		else
		{
			if(sx+1>=0&&s[sx+1][sy]=='.') sx++;
		}
	}
	cout<<sx+1<<" "<<sy+1<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}	
	return 0;
}