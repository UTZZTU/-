#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,y,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0};
double sum;
map<pair<int,int>,bool> mp;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		sum+=2;
		if(mp[{x,y}]==true)
		{
			sum-=2;
			continue;
		}
		for(int j=0;j<4;j++)
		{
			int xx=x+dirx[j],yy=y+diry[j];
			if(mp[{xx,yy}]==true) sum-=0.5;
		}
		mp[{x,y}]=true;
	}
	cout<<sum<<endl;
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