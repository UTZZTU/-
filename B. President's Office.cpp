#include <bits/stdc++.h>
using namespace std;
int n,m;
char c;
string s[110];
set<char> st;
int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
void solve()
{
	cin>>n>>m>>c;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]==c)
			{
				for(int k=0;k<4;k++)
				{
					int xx=i+dx[k],yy=j+dy[k];
					if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]!=c&&s[xx][yy]!='.') st.insert(s[xx][yy]);
				}
			}
		}
	}
	cout<<st.size()<<endl;
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