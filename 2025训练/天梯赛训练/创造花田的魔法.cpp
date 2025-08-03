#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m;
string s[1010],p[1010];
bool hh(int x,int y)
{
	for(int i=x-1;i<=x+1;i++)
	{
		for(int j=y-1;j<=y+1;j++)
		{
			if(i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='H') return true;
		}
	}
	return false;
}
int h(int x,int y)
{
	int res=0;
	for(int i=x-1;i<=x+1;i++)
	{
		for(int j=y-1;j<=y+1;j++)
		{
			if(i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='L') res++;
		}
	}
	return res;
}
bool yh(int x,int y)
{
	for(int i=x-1;i<=x+1;i++)
	{
		for(int j=y-1;j<=y+1;j++)
		{
			if(i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='L') return true;
		}
	}
	return false;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		p[i]=s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='M'||s[i][j]=='H'||hh(i,j)) continue;
			if(h(i,j)>=9) p[i][j]='S';
			else if(s[i][j]!='L'&&yh(i,j)) p[i][j]='N';
			else if(s[i][j]!='L') p[i][j]='B';
		}
	}
	for(int i=0;i<n;i++) cout<<p[i]<<endl;
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